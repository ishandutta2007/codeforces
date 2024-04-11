#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n, depth[MAXN], anc[MAXN][MAXL];
vector<int> adj[MAXN];
ll a[MAXN], ans=0;

void init_lca(int c, int p, int d){
	depth[c]=d, anc[c][0]=p;
	for (int i=1; i < MAXL; i++) anc[c][i] = (anc[c][i-1]==-1?-1:anc[anc[c][i-1]][i-1]);
	for (auto nxt : adj[c]) if (nxt != p) init_lca(nxt, c, d+1);
}
int jmp(int a, int h){
	for (int i = 0; i < MAXL; i++) if ((h>>i)&1) a = anc[a][i];
	return a;
}
int lca(int a, int b){
	if (depth[a] < depth[b]) swap(a, b);
	a = jmp(a, depth[a]-depth[b]);
	if (a==b) return a;
	for (int i = MAXL-1; i >= 0; i--){
		if (anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
	}
	assert(anc[a][0]==anc[b][0]);
	return anc[a][0];
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    int ROOT = min_element(a, a+n)-a;
    init_lca(ROOT, -1, 0);

    for (int i = 0; i < n; i++) if (i != ROOT) {
        ll cur=INF;
        for (int j = 0; j < MAXL; j++) if (anc[i][j] != -1) {
            int p = anc[i][j];
            cur = min(cur, j*min(a[i], a[p])+a[i]+a[p]);
        }
        int j=0; while (anc[i][j] != -1) j++;
        cur = min(cur, j*min(a[i], a[ROOT])+a[i]+a[ROOT]);

        ans += cur;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}