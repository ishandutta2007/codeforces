#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 1e9 + 3;
const int max_n = (1 << 19);

int n;
vector<int> gr[max_n];
int dp[max_n];

bool used[max_n];
vector<int> ord;
void topsort(int v) {
    if (used[v]) return;
    used[v] = true;
    for (int to : gr[v])
        topsort(to);
    ord.pb(v);
}

void run() {
    int m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i)
        gr[i].clear();
    fill(used, used + n, 0);
    fill(dp, dp + n, 0);
    ord.clear();

    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1, --v2;
        gr[v1].pb(v2);
    }
    topsort(0);
    dp[0] = 1;
    reverse(all(ord));

    fill(used, used + n, 0);
    for (int v : ord) {
        used[v] = true;
        for (int to : gr[v]) {
            if (used[to]) {
                dp[to] = inf;
            }
        }
    }
    for (int v : ord) {
        for (int to : gr[v]) {
            if (dp[to] < inf && (dp[to] < 2 || dp[v] >= inf)) dp[to] += dp[v];
        }
        if (dp[v] < inf && dp[v] > 2) dp[v] = 2;
    }
    for (int i = 0; i < n; ++i) {
        cout << (dp[i] >= inf ? -1 : dp[i]) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}