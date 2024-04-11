#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,mmx,tune=native")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, -1, -1,  0, +1, +1, +1,  0};
const int dc[] = {-1,  0, +1, +1, +1,  0, -1, -1};

/*  Solve the problem in reverse: find and remove a non-8-articulation 4-reachable from infinity 
    cell N times, and restore the order in reverse order (or report that it is impossible).
 
    If cells are all 8-connected, then there is a non-8-articulation 4-reachable from infinity cell.
    
    Let the region of a c0 = 4-reachable empty cells surrounding this cell, and different cell c1
    and c2 are in one region if there are 4-paths only using 8-negihbours of c0. (c1 and c2 are
    4-reachable negihbours of c0)

    For all 4-reachable from infinity full cells, if it is a non-articulation, then all regioin
    must belong to different components. If two regions belong to the same component, then there
    are no alternate paths connecting some 8-reachable cells through c0 in the graph.
*/

struct DisjointSet {

    vector<int> p, set_size;
    vector<vector<int>> members;

    int size;
    bool need_members;

    DisjointSet(bool yes = 0): need_members(yes) {}
    
    void init(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size = n;

        if (need_members) {
            members.resize(n);
            for (int i = 0; i < n; i++) members[i].emplace_back(i);
        } else {
            set_size.assign(n, 1);
        }
    }

    int find(int n) {
        return (p[n] == n)? n : p[n] = find(p[n]);
    }
    
    inline bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;

        if (need_members) {
            if (members[a].size() < members[b].size()) swap(a, b);
            for (auto i : members[b]) members[a].emplace_back(i);
            members[b].clear();
        } else {
            if (set_size[a] < set_size[b]) swap(a, b);
            set_size[a] += set_size[b];
            set_size[b] = 0;
        }

        p[b] = a;
        size--;
        return true;
    }

    inline vector<int> get_members(int n) {
        return members[find(n)];
    }
    
    inline int get_size(int n) {
        return (need_members)? members[find(n)].size() : set_size[find(n)];
    }

};

int N;
map<pair<int, int>, int> full_cell, empty_cell, cell;
vector<pair<int, int>> cell_id;
DisjointSet component(1); //connected components of empty cells

namespace validity_check {

    /*  Run DFS on 8-reachable graph of full cells. It can be proven that
        if the given graph is 8-connected, then there is at least one cell
        which is non-8-articulation 4-reachable from infinity. Thus a solution
        exists if and only if the graph is 8-connected.
    */

    vector<vector<int>> G;
    vector<int> vis;
    
    int flood(pair<int, int> n) {
        int id = cell[n];
        if (vis[id]) return 0;
        vis[id] = 1;
        int res = 1;

        for (int d = 0; d < 8; d++) {
            int tr = n.first + dr[d], tc = n.second + dc[d];
            if (full_cell.find(make_pair(tr, tc)) == full_cell.end()) continue;
            res += flood(make_pair(tr, tc));
        }

        return res;
    }

    bool solution_exists() {
        G.resize(full_cell.size()), vis.resize(full_cell.size());
        int connected_size = flood(cell_id[0]);
        return (connected_size == N);
    }
}

namespace solve {
    
    pair<int, int> infinity_cell;

    vector<int> vis;
    
    void flood(pair<int, int> n, int par) {
        int id = cell[n];
        if (vis[id]) return;
        vis[id] = 1;
        component.join(id, par);

        for (int d = 1; d < 8; d += 2) { //4-direction
            int tr = n.first + dr[d], tc = n.second + dc[d];
            if (empty_cell.find(make_pair(tr, tc)) == empty_cell.end()) continue;
            flood(make_pair(tr, tc), par);
        }
    }

    vector<int> regions, small;
    vector<DisjointSet> near;
    
    vector<int> infinity_reachable;
    vector<array<int, 8>> empty_neighbour;
    vector<bool> is_removable, in_queue;

    inline bool is_valid(pair<int, int> p) {
        int id = cell[p];
        regions.clear();
        small.clear();

        for (int d = 1; d < 8; d += 2) {
            int tr = p.first + dr[d], tc = p.second + dc[d];
            if (!empty_neighbour[id][d]) continue;

            small.emplace_back(near[id].find(((d - 1) / 2)));
            regions.emplace_back(component.find(cell[make_pair(tr, tc)]));
        }

        sort(small.begin(), small.end());
        sort(regions.begin(), regions.end());

        small.resize(unique(small.begin(), small.end()) - small.begin());
        regions.resize(unique(regions.begin(), regions.end()) - regions.begin());

        if (!infinity_reachable[id]) infinity_reachable[id] = (count(regions.begin(), regions.end(), component.find(cell[infinity_cell])) > 0);
        if (!infinity_reachable[id]) return false;
        return (regions.size() == small.size()); //all regions must be different components
    }

    vector<int> get_solution() {

        /*  We can check if a cell is 4-reachable from infinity in O(1) with
            the help of dijoinst set. We can also determine if a cell is an
            articulation the same way. Thus each time we are going to remove
            a cell, we can just check all N possible skyscrapers.

            However, each 4-reachable cell can change its status as an
            articulation or non-articulation at most 2 times: a non-articulation
            (as there are other connecting paths), an articulation (all other
            connecting paths are already removed), a non-articulation (it becomes
            a leaf).

            Thus if we join two components, we can afford to recompute all 8-negihbours 
            of the one with less size and achieve N log N by the weighted-union heursitic.

            Notice that the number of regions are only changed if and only if a cell is
            an 8-neighbour of the removed cell. Thus we can save this data in an array
            and update only when needed, to avoid recomputation.
        */

        infinity_cell = cell.begin()->first;
        for (auto i : cell) infinity_cell = min(infinity_cell, i.first);

        infinity_reachable.resize(full_cell.size());
        empty_neighbour.resize(full_cell.size());
        is_removable.resize(full_cell.size());
        in_queue.resize(full_cell.size());
        near.resize(full_cell.size());

        /* Initial merging of empty cell components */
        vis.assign(cell.size(), 0);
        flood(infinity_cell, cell[infinity_cell]);
        
        for (auto i : cell) {
            if (empty_cell.find(i.first) == empty_cell.end()) continue;
            flood(i.first, i.second);
        }

        /* Compute data (regions and components) to determine whether cell is an articulation */
        for (auto i : full_cell) {
            for (int d = 0; d < 8; d++) {
                int tr = i.first.first + dr[d], tc = i.first.second + dc[d];
                empty_neighbour[i.second][d] = (empty_cell.find(make_pair(tr, tc)) != empty_cell.end());
            }

            near[i.second].init(4);
            for (int d = 1; d < 8; d += 2) {
                int c1 = empty_neighbour[i.second][d],
                    c2 = empty_neighbour[i.second][(d + 1) % 8],
                    c3 = empty_neighbour[i.second][(d + 2) % 8];
                
                if (c1 == c2 && c2 == c3 && c3 == 1) near[i.second].join(((d - 1) / 2), (((d - 1) / 2) + 1) % 4);
            }
        }

        /* Initialize removable cells for first pass */
        priority_queue<int> removable; //get highest cell index that is removable
        for (auto i : full_cell) if (is_valid(i.first)) {
            removable.emplace(i.second);
            is_removable[i.second] = in_queue[i.second] = 1;
        }
        
        vector<int> res;
        vector<int> change;
        vector<pair<int, int>> update_list;

        update_list.reserve(4 * N);
        res.reserve(N);
        change.reserve(N);

        while (full_cell.size() > 0) {
            while (!is_removable[removable.top()]) in_queue[removable.top()] = 0, removable.pop();
            int candidate = removable.top();
            pair<int, int> P = cell_id[candidate];

            removable.pop();
            is_removable[candidate] = 0;
            in_queue[candidate] = 0;

            res.emplace_back(candidate + 1);
            full_cell.erase(full_cell.find(P));
            empty_cell.emplace(P, candidate);

            update_list.clear();

            /* Update connected components of cells affected */
            for (int d = 1; d < 8; d += 2) {
                int tr = P.first + dr[d], tc = P.second + dc[d];
                int P_id = cell[P], neighbour_id = cell[make_pair(tr, tc)];

                if (empty_cell.find(make_pair(tr, tc)) == empty_cell.end()) continue;
                if (component.find(P_id) == component.find(neighbour_id)) continue;

                if (component.get_size(neighbour_id) > component.get_size(P_id)) {
                    change = component.get_members(P_id);                    
                } else {
                    change = component.get_members(neighbour_id);
                }

                component.join(neighbour_id, P_id);
                
                for (auto i : change) {
                    pair<int, int> cur = cell_id[i];

                    for (int change_d = 0; change_d < 8; change_d++) {
                        int change_tr = cur.first + dr[change_d], change_tc = cur.second + dc[change_d];
                        if (full_cell.find({change_tr, change_tc}) == full_cell.end()) continue;

                        update_list.emplace_back(change_tr, change_tc);
                    }
                }
            }

            /* Update data needed to determine articulation cells */
            for (int d = 0; d < 8; d++) {
                int tr = P.first + dr[d], tc = P.second + dc[d];    
                if (full_cell.find(make_pair(tr, tc)) == full_cell.end()) continue;

                /* Update empty neighbours for 8-neighbours of removed cell */
                int id = cell[make_pair(tr, tc)];
                empty_neighbour[id][(d + 4) % 8] = 1;

                /* Update number of regions for 8-neighbours of removed cell */
                for (int d2 = 1; d2 < 8; d2 += 2) {
                    int c1 = empty_neighbour[id][d2],
                        c2 = empty_neighbour[id][(d2 + 1) % 8],
                        c3 = empty_neighbour[id][(d2 + 2) % 8];
                    
                    if (c1 == c2 && c2 == c3 && c3 == 1) near[id].join(((d2 - 1) / 2), (((d2 - 1) / 2) + 1) % 4);
                }   
            }

            sort(update_list.begin(), update_list.end());
            update_list.resize(unique(update_list.begin(), update_list.end()) - update_list.begin());
            
            for (auto i : update_list) {
                int id = cell[i];
                is_removable[id] = is_valid(i);

                if (is_removable[id] && !in_queue[id]) removable.emplace(id);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> N >> t;

    for (int i = 0; i < N; i++) {
        pair<int, int> p; cin >> p.first >> p.second;

        full_cell.emplace(p, cell.size());
        cell.emplace(p, cell.size());
    }

    for (auto i : full_cell) {
        for (int d = 0; d < 8; d++) {
            int tr = i.first.first + dr[d], tc = i.first.second + dc[d];
            if (cell.find(make_pair(tr, tc)) != cell.end()) continue;

            empty_cell.emplace(make_pair(tr, tc), cell.size());
            cell.emplace(make_pair(tr, tc), cell.size());
        }
    }

    component.init(cell.size());
    cell_id.resize(cell.size());
    for (auto i : cell) cell_id[i.second] = i.first;

    if (!validity_check::solution_exists()) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<int> ans = solve::get_solution();
    for (auto i : ans) cout << i << "\n";

    return 0;
}