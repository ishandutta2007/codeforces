#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 1e6+20,mod = 1e9+7,inf = 1e18+10,sq = 300;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}

inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
vector<pll> out[N];
int ind[N],n;
ll d[N];
void build(int l,int r,int v = 1){
    if (r-l == 1){
        ind[l] = v;
        return;
    }
    int u = (v << 1),m = (l+r) >> 1;
    int x = 4*(n+1);
    out[v].pb({u,0});
    out[v].pb({u|1,0});
    out[u+x].pb({v+x,0});
    out[u+1+x].pb({v+x,0});
    build(l,m,u);
    build(m,r,u|1);
}
void que(int l,int r,int s,int e,bool f,int g,int w,int v = 1){
    if (s >= r || l >= e || s >= e) return;
    if (s <= l && r <= e){
        if (f){
            out[v+4*(n+1)].pb({g,w});
        }
        else{
            out[g].pb({v,w});
        }
        return;
    }
    int u = (v << 1),m = (l+r) >> 1;
    que(l,m,s,e,f,g,w,u);
    que(m,r,s,e,f,g,w,u|1);
}
inline void dij(int s){ 
	set<pair<ll, int> > st; 
    st.insert({0, s});
	d[s] = 0;
	while(!st.empty()) {
		pll p = (*st.begin());
		st.erase(st.begin());
        int v = p.Y;
		for(pll u : out[v]) {
			if(d[u.X] > d[v]+u.Y) {
				st.erase({d[u.X],u.X});
				d[u.X] = d[v]+u.Y;
				st.insert({d[u.X],u.X});
			}
		}
	}
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    memset(d,63,sizeof d);
    int q,s;
    cin >> n >> q >> s;
    build(0,n+1);
    int x = 4*(n+1);
    rep(i,0,q){
        int t,v;
        cin >> t >> v;
        if (t == 1){
            int u,w;
            cin >> u >> w;
            out[ind[v]].pb({ind[u],w});
            continue;
        }
        int l,r,w;
        cin >> l >> r >> w;
        if (t == 2) que(0,n+1,l,r+1,0,ind[v],w);
        else que(0,n+1,l,r+1,1,ind[v]+x,w);
    }
    rep(i,1,n+1){
        out[ind[i]].pb({ind[i]+x,0});
        out[ind[i]+x].pb({ind[i],0});
    }
    dij(ind[s]);
    rep(i,1,n+1){
        if (min(d[ind[i]+x],d[ind[i]]) > inf) cout << -1 << ' ';
        else cout << min(d[ind[i]+x],d[ind[i]]) << ' ';
    }
}