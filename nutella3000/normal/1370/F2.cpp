#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7, mod = 1e9 + 7;
const int max_n = 1001;

int n, root, spec_d;
int dist[max_n];
bool bad[max_n];
vector<int> gr[max_n];

void build(int v, int pr) {
    dist[v] = dist[pr] + 1;
    //cout << v << " " << dist[v] << endl;
    for(int i : gr[v]) if (i != pr) build(i, v);
}

void dfs(int v, int pr) {
    bad[v] = true;
    for(int i : gr[v]) {
        if (i != pr && i != root) dfs(i, v);
    }
}

pii print(vector<int> &a) {
    cout << "? " << a.size() << " ";
    for(int i : a) cout << i + 1 << " ";
    cout << endl;
    a.clear();

    pii res;
    cin >> res.first >> res.second;
    return res;
}

void solve() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        bad[i] = false;
        gr[i].clear();
    }

    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }

    vector<int> pr;
    for(int i = 0;i < n;i++) pr.emplace_back(i);
    pii temp = print(pr);
    root = temp.first - 1;
    spec_d = temp.second;
    dist[root] = -1;
    build(root, root);

    //cout << "dist ";
    //for(int i = 0;i < n;i++) cout << dist[i] << " ";
    //cout << endl;

    int first, second;

    int l = (spec_d + 1) / 2 - 1;
    int r = spec_d + 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        for(int i = 0;i < n;i++) {
            if (dist[i] == mid) pr.emplace_back(i);
        }
        if (pr.empty()) {
            r = mid;
            continue;
        }
        temp = print(pr);

        if (temp.second == spec_d) {
            l = mid;
            first = temp.first - 1;
        }else r = mid;
    }

    dfs(first, first);

    for(int i = 0;i < n;i++) {
        if (!bad[i] && dist[i] == spec_d - dist[first]) pr.emplace_back(i);
    }
    temp = print(pr);
    second = temp.first - 1;

    cout << "! " << first + 1 << " " << second + 1 << endl;
    string temp1;
    cin >> temp1;
}



signed main() {
    #ifdef local
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}