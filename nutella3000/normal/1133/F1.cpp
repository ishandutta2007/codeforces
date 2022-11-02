#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef double ld;
 
const int inf = 1e16; 
const int max_n = 2e5 + 1;

int n;
vector<int> gr[max_n];
bool used[max_n];
vector<pii> res;

void rec(int st) {
    deque<int> bfs;
    bfs.emplace_back(st);
    used[st] = true;

    while(bfs.size()) {
        int v = bfs.front();
        bfs.pop_front();

        for(int i : gr[v]) {
            if (used[i]) continue;
            used[i] = true;
            bfs.emplace_back(i);
            res.emplace_back(v + 1, i + 1);
        }
    }
}

void solve() {
    int m;
    cin >> n >> m;
    vector<int> deg(n);
    int root = 0;

    for(int i = 0;i < m;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
        deg[v1]++;
        deg[v2]++;
        if (deg[v1] > deg[root]) root = v1;
        if (deg[v2] > deg[root]) root = v2;
    }

    rec(root);

    for(auto i : res) 
        cout << i.fi << " " << i.se << endl;
}
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}