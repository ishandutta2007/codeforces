#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9,sq = 4e7;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int par[N];
int cmp[N];
int x[N],y[N],t[N];
int getpar(int v){
    if (par[v] == v) return v;
    return par[v] = getpar(par[v]);
}
void merge(int u,int v){
    u = getpar(u);
    v = getpar(v);
    if (u == v) return;
    par[u] = v;
    cmp[v] = min(cmp[u],cmp[v]);
    cmp[u] = -1;
}
map<int,set<pll>> st,st2;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        rep(i,1,n+1){
            cin >> x[i] >> y[i] >> t[i];
            par[i] = i;
            cmp[i]= t[i];
            st[x[i]].insert({y[i],i});
            st2[y[i]].insert({x[i],i});
        }
        rep(i,1,n+1){
            auto it = st[x[i]].upper_bound({y[i],i});
            if (it != st[x[i]].end() && x[i] == x[it->Y]){
                int v = it->X;
                if (v-y[i] <= k)
                    merge(i,it->Y);
            }
            it = st2[y[i]].upper_bound({x[i],i});
            if (it != st2[y[i]].end() && y[i] == y[it->Y]){
                int v = it->X;
                if (v-x[i] <= k){
                    merge(i,it->Y);
                }
            }
        }
        vector<int> ve;
        rep(i,1,n+1){
            if (cmp[i] > -1){
                ve.pb(cmp[i]);
            }
        }
        sort(ve.begin(),ve.end());
        int sz = ve.size();
        int cnt = 0;
        int ans = 0;
        repr(i,sz-1,0){
            ans = max(ans,min(cnt,ve[i]));
            if (ve[i] > cnt) cnt++;
        }
        cout << ans << endl;
        st.clear();
        st2.clear();
    }
}