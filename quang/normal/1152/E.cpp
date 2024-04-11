#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct EulerianGraph {
    vector< vector< pair<int, int> > > a;
    int num_edges;

    EulerianGraph(int n) {
        a.resize(n + 1);
        num_edges = 0;
    }

    void add_edge(int u, int v, bool undirected = true) {
        a[u].push_back(make_pair(v, num_edges));
        if (undirected) a[v].push_back(make_pair(u, num_edges));
        num_edges++;
    }

    vector<int> get_eulerian_path(int startNode) {
        vector<int> path, s;
        vector<bool> was(num_edges);
        s.push_back(startNode); // start of eulerian path
        while (!s.empty()) {
            int u = s.back();
            bool found = false;
            while (!a[u].empty()) {
                int v = a[u].back().first;
                int e = a[u].back().second;
                a[u].pop_back();
                if (was[e]) continue;
                was[e] = true;
                s.push_back(v);
                found = true;
                break; 
            }
            if (!found) {
                path.push_back(u);
                s.pop_back();
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int n;
int b[N], c[N];
vector<int> val;
int deg[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        val.push_back(b[i]);
    }
    for (int i = 1; i < n; i++) {
        cin >> c[i];
        val.push_back(c[i]);
    }   
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    if (val.size() > n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        b[i] = lower_bound(val.begin(), val.end(), b[i]) - val.begin();
    }
     for (int i = 1; i < n; i++) {
        c[i] = lower_bound(val.begin(), val.end(), c[i]) - val.begin();
    }
    EulerianGraph eg(n);
    for (int i = 1; i < n; i++) {
        eg.add_edge(b[i], c[i]);
        deg[b[i]]++;
        deg[c[i]]++;
        if (b[i] > c[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    int num = 0;
    int id = -1;
    for (int i = 0; i < val.size(); i++) {
        if (deg[i] & 1) {
            num++;
            id = i;
        }
    }
    if (num > 2 || num == 1) {
        cout << -1 << endl;
        return 0;
    }
    int startNode = 0;
    if (id != -1) startNode = id;
    vector<int> res = eg.get_eulerian_path(startNode);
    if (res.size() != n) {
        cout << -1 << endl;
        return 0;
    }
    for (int u : res) cout << val[u] << ' ';
        cout << endl;
    return 0;
}