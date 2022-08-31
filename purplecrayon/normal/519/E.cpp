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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

#include <bits/stdc++.h>
using namespace std;


int n, depth[MAXN], anc[MAXN][MAXL], sub[MAXN];
vector<int> adj[MAXN];

int init_lca(int c=0, int p=-1, int d=0){
	depth[c]=d, anc[c][0]=p;
    sub[c] = 1;
	for (int i=1; i < MAXL; i++) anc[c][i] = (anc[c][i-1]==-1?-1:anc[anc[c][i-1]][i-1]);
	for (auto nxt : adj[c]) if (nxt != p) sub[c] += init_lca(nxt, c, d+1);
    return sub[c];
}
int jmp(int a, int h) {
	for (int i = 0; i < MAXL; i++) if ((h>>i)&1) {
        a = anc[a][i];
        if (a == -1) return -1;
    }
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
int dist(int a, int b){ return depth[a]+depth[b]-2*depth[lca(a, b)]; }

void solve(){
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    init_lca();
    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b, --a, --b;
        int l=lca(a, b);
        if (dist(a, b)&1) cout << 0 << '\n';
        else if (a == b) cout << n << '\n';
        else if (depth[a] == depth[b]) {
            int ca=jmp(a, depth[a]-depth[l]-1), cb=jmp(b, depth[b]-depth[l]-1);
            cout << n-sub[ca]-sub[cb] << '\n';
        } else {
            if (depth[a] < depth[b]) swap(a, b);
            int top=0;
            if (depth[a] >= dist(a, b)/2 - 1)
                top=jmp(a, dist(a, b)/2 - 1);
            cout << (top?sub[anc[top][0]]:n)-sub[top] << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}