#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
inline bool lucky(int w){
    while (w != 0){
        if (w%10 != 4 && w%10 != 7) return 0;
        w /= 10;
    }
    return 1;
}
vector <int> comp[N];
int c[N],par[N];
int getpar(int x){
    if (par[x] == x) return x;
    return par[x] = getpar(par[x]);
}
void merge(int x,int y){
    if (getpar(x) == getpar(y)) return;
    if (comp[par[x]].size() < comp[par[y]].size()) swap(x,y);
    int sz = comp[par[y]].size();
    while (sz){
        comp[par[x]].pb(comp[par[y]][sz-1]);
        sz--;
        comp[par[y]].pop_back();
    }
    par[par[y]] = par[x];
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    int n;
    cin >> n;
    rep(i,1,n+1){
        par[i] = i;
        comp[i].pb(i);
    }
    rep(i,0,n-1){
        int x,y,w;
        cin >> x >> y >> w;
        if (!lucky(w))
            merge(x,y);
    }
    ll ans = 0;
    rep(i,1,n+1){
        ans += 1ll * comp[i].size() * (n-comp[i].size()) * (n-comp[i].size()-1);
    }
    cout << ans;
    return 0;
}