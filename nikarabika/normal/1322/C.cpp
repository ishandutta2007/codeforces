//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 500 * 1000 + 100;
vector<int> vec[maxn],
    adj[maxn];
int cnt[maxn],
    sizof[maxn],
    setof[maxn];
LL num[maxn],
   sum[maxn];
bool mark[maxn];
int comp;

LL gcd(LL x, LL y) {
    return y == 0 ? x : gcd(y, x % y);
}

void jodakon(vector<int> &s) {
    for (int u: s) {
        cnt[setof[u]] = 0;
        mark[u] = false;
        vec[setof[u]].clear();
    }
    for (int u: s) {
        cnt[setof[u]]++;
        vec[setof[u]].PB(u);
    }
    for (int u: s)
        if (!mark[u] and cnt[setof[u]] < sizof[setof[u]]) {
            int newset = comp++;
            int oldset = setof[u];
            for (int v: vec[oldset]) {
                setof[v] = newset;
                mark[v] = true;
            }
            sizof[oldset] -= sz(vec[oldset]);
            sizof[newset] = sz(vec[oldset]);
        }
}

int solve() {
    comp = 1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        setof[i] = 0;
        sizof[i] = 0;
        sum[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sizof[0] = n + 1;
    for (int i = 0; i < m; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(se);
    }
    for (int i = 0; i < n; i++)
        jodakon(adj[i]);
    for (int i = 0; i < n; i++)
        sum[setof[i]] += num[i];
    LL ans = 0;
    for (int i = 1; i < comp; i++) {
        ans = gcd(ans, sum[i]);
    }
    cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}