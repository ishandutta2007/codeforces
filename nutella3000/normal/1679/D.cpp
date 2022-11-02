#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e15 + 7;
const int N = 1e6 + 3;

int n, m;
int a[N];
vector<int> gr[N];
int used[N], depth[N];

bool dfs(int v, int num) {
    if (used[v] || a[v] > num) return false;
    used[v] = depth[v] = 1;
    for (int to : gr[v]) {
        if (used[to] == 1 || dfs(to, num)) return true;
        chmax(depth[v], depth[to]+1);
    }
    used[v] = 2;
    return false;
}

void run() {
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int v1, v2; cin >> v1 >> v2; --v1, --v2;
        gr[v1].eb(v2);
    }
    int l = -2, r = inf;
    while (r - l > 1) {
        int mid = (l + r) / 2;

        fill(used, used+n, 0);
        fill(depth, depth+n, 0);
        bool cyc = false;
        for (int i = 0; i < n; ++i)
            if (!used[i]) cyc |= dfs(i, mid);

        if (cyc || *max_element(depth, depth+n) >= k) r = mid;
        else l = mid;
    }
    cout << (r == inf ? -1 : r) << endl;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}