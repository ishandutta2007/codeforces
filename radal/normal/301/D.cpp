#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int p[N],ind[N],seg[N*4],pre[N],ans[N];
bool mark[N];
vector<pll> qu[N];
vector<int> ta[N],ve[N];
void add(int l,int r,int val,int i,int v){
    if (r-l == 1){
        seg[v]+=val;
        return;
    }
    seg[v]+=val;
    int m = (l+r+1)/2;
    if (i < m)
        add(l,m,val,i,2*v);
    else
        add(m,r,val,i,2*v+1);
}
int que(int l,int r,int s,int e,int v){
    if (l >= s && r <= e)
        return seg[v];
    if (l >= e || s >= r)
        return 0;
    int m = (l+r+1)/2;
    return que(l,m,s,e,2*v)+que(m,r,s,e,2*v+1);
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        cin >> p[i];
        ind[p[i]] = i;
    }
    rep(i,1,n)
        for (int j = i+i; j <=n; j+=i)
            ta[j].pb(i);
    rep(i,1,n+1){
        for (int u : ta[i]){
            if (ind[i] > ind[u])
                ve[ind[i]].pb(ind[u]);
            else
                ve[ind[u]].pb(ind[i]);
        }
    }
    rep(i,0,m){
        int l,r;
        cin >> l >> r;
        l--;
        qu[r-1].pb({l,i});
    }
    rep(i,0,n){
        add(0,n,ve[i].size(),i,1);
        for (int u : ve[i])
            add(0,n,1,u,1);
        pre[i] = que(0,n,0,i+1,1);
        for (pll u : qu[i]){
            int l = u.X;
            if (!l) ans[u.Y] = pre[i]/2+i+1;
            else ans[u.Y] = (pre[i]-2*que(0,n,0,l,1)+pre[l-1])/2+i+1-l;
        }
    }
    rep(i,0,m) cout << ans[i] << endl;
    return 0;
}