#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = v.size();

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

const int INF = 1e9 + 5;

int N, M, G;
vector<vector<int>> adj;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    G = ceil(sqrt(N));
    adj.assign(N, {});

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> done(N, false);
    vector<int> path_index(N, -INF);
    vector<int> path, independent_set;

    while (true) {
        if (path.empty()) {
            for (int i = 0; i < N; i++)
                if (!done[i]) {
                    path_index[i] = 0;
                    path = {i};
                    break;
                }
        }

        dbg(path);
        int current = path.back();
        bool found = false;

        for (int neighbor : adj[current])
            if (!done[neighbor] && path_index[neighbor] <= (int) path.size() - G) {
                if (path_index[neighbor] >= 0) {
                    cout << 2 << '\n';

                    int cycle_size = (int) path.size() - path_index[neighbor];
                    cout << cycle_size << '\n';
                    output_vector(path, true, path.size() - cycle_size, path.size());
                    return 0;
                }

                dbg(current, neighbor, path_index[neighbor]);
                path_index[neighbor] = path.size();
                path.push_back(neighbor);
                found = true;
                break;
            }

        if (!found) {
            independent_set.push_back(current);
            dbg(independent_set);

            if ((int) independent_set.size() >= G) {
                cout << 1 << '\n';
                output_vector(independent_set, true);
                return 0;
            }

            int remove = min((int) path.size(), G - 1);

            for (int i = 0; i < remove; i++) {
                done[path.back()] = true;
                path_index[path.back()] = INF;
                path.pop_back();
            }
        }
    }
}