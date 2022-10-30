#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
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
typedef pair<long double,long double> pld;
const long long int N = 2e6+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 5e3+10;
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
int par[N],sz[N],o;
set<pll> st,st2;
int ans;
int getpar(int v){
    if (v == par[v]) return v;
    return par[v] = getpar(par[v]);
}
inline void mg(int u,int v){
    v = getpar(v);
    u = getpar(u);
    if (u != v){
        bool f = (st.find({sz[u],u}) == st.end());
        bool f2 = (st.find({sz[v],v}) == st.end());
        if (f && f2){
            st2.erase({sz[u],u});
            st2.erase({sz[v],v});
            sz[v] += sz[u];
            par[u] = v;
            st2.insert({sz[v],v});
            if (!st.empty()){
                pll p = *(st.rbegin());
                st.erase(p);
                st2.insert(p);
                ans += p.X;
            }
            return;
        }
        if (f2){
            swap(u,v);
            swap(f,f2);
        }
        if (f){
            st.erase({sz[v],v});
            st2.erase({sz[u],u});
            sz[u] += sz[v];
            par[v] = u;
            ans += sz[v];
            st2.insert({sz[u],u});
            return;
        }
        st.erase({sz[v],v});
        st.erase({sz[u],u});
        sz[v] += sz[u];
        par[u] = v;
        pll p = *(st2.begin());
        if(p.X < sz[v]){
            ans -= p.X;
            ans += sz[v];
            st.insert(p);
            st2.erase(p);
            st2.insert({sz[v],v});
        }
        else st.insert({sz[v],v});
        return;
    }
    o++;
    if (!st.empty()){
        pll p = *(st.rbegin());
        st.erase(p);
        st2.insert(p);
        ans += p.X;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--){
        int n,d;
        cin >> n >> d;
        rep(i,1,n){
            par[i] = i;
            sz[i] = 1;
            st.insert({1,i});
        }
        par[n] = n;
        sz[n] = 1;
        st2.insert({1,n});
        ans = 1;
        rep(i,0,d){
            int u,v;
            cin >> v >> u;
            mg(u,v);
            cout << ans-1 << endl;
        }
    }
}