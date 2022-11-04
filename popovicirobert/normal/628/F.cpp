#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

struct MaxFlow {

    static const int INF = 1e9;

    struct Edge {
        int x, y;
        int id1, id2;
    };
    vector <Edge> edges;
    vector < vector <int> > g;
    vector <int> vis, from;
    vector <int> cap, flow;

    inline void init(int _n) {
        g.resize(_n + 1);
        vis.resize(_n + 1);
        from.resize(_n + 1);
    }
    inline void addEdge(int x, int y, int c) {
        g[x].push_back(edges.size());
        edges.push_back({x, y, edges.size(), edges.size() + 1});
        cap.push_back(c), flow.push_back(0);

        g[y].push_back(edges.size());
        edges.push_back({y, x, edges.size(), edges.size() - 1});
        cap.push_back(0), flow.push_back(0);
    }
    inline bool bfs(int S, int D, int &now) {
        queue <int> Q;
        Q.push(S);
        vis[S] = ++now;
        while(Q.size()) {
            int nod = Q.front();
            Q.pop();
            for(auto it : g[nod]) {
                int cur = edges[it].y;
                int id = edges[it].id1;
                if(vis[cur] < now && flow[id] < cap[id]) {
                    Q.push(cur);
                    vis[cur] = now;
                    from[cur] = it;
                    if(D == cur) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    inline int solve(int S, int D) {
        int ans = 0, now = 0;
        fill(vis.begin(), vis.end(), 0), fill(flow.begin(), flow.end(), 0);
        while(bfs(S, D, now)) {
            int mn = INF;
            int nod = D;
            while(nod != S) {
                int id = from[nod];
                mn = min(mn, cap[id] - flow[id]);
                nod = edges[id].x;
            }
            nod = D;
            while(nod != S) {
                int id = from[nod];
                flow[id] += mn;
                flow[edges[id].id2] -= mn;
                nod = edges[id].x;
            }
            ans += mn;
        }
        return ans;
    }

};

const int MAXQ = 10005;

pair <int, int> arr[MAXQ + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, b, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> b >> q;
    for(i = 1; i <= q; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    arr[++q] = {b, n};
    sort(arr + 1, arr + q + 1);
    int S = q + b + 5 + 1;
    int D = S + 1;
    MaxFlow net;
    net.init(D);
    for(i = 1; i <= q; i++) {
        if(arr[i].first - arr[i - 1].first < arr[i].second - arr[i - 1].second || arr[i].second < arr[i - 1].second) {
            cout << "unfair";
            return 0;
        }
        if(arr[i].first == arr[i - 1].first && arr[i].second != arr[i - 1].second) {
            cout << "unfair";
            return 0;
        }
        net.addEdge(S, i, arr[i].second - arr[i - 1].second);
        for(j = arr[i - 1].first + 1; j <= arr[i].first; j++) {
            net.addEdge(i, j + q, 1);
            net.addEdge(j + q, q + b + j % 5 + 1, 1);
        }
    }
    for(i = 1; i <= 5; i++) {
        net.addEdge(q + b + i, D, n / 5);
    }
    if(net.solve(S, D) == n) {
        cout << "fair";
    }
    else {
        cout << "unfair";
    }
    //cin.close();
    //cout.close();
    return 0;
}