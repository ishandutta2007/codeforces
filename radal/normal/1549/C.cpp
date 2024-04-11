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
typedef pair<ll,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int d[N],t[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    while (T--){
        int n,m;
        cin >> n >> m;
        rep(i,0,m){
            int u,v;
            cin >> u >> v;
            d[u]++;
            d[v]++;
            if (u < v) swap(u,v);
            t[u]++;
        }
        int ans = 0;
        rep(i,1,n+1){
            if (t[i] == d[i]) ans++;
        }
        int q;
        cin >> q;
        rep(j,0,q){
            int c;
            cin >> c;
            if (c == 3){
                cout << ans << endl;
                continue;
            }
            int u,v;
            cin >> u >> v;
            if (u > v) swap(u,v);
            if (c == 2){
                d[u]--;
                d[v]--;
                t[v]--;
                if (d[u] == t[u]) ans++;
                if (d[u] == t[u]-1) ans--;
                continue;
            }
            d[u]++;
            d[v]++;
            t[v]++;
            if (d[u] == t[u]) ans++;
            if (d[u] == t[u]+1) ans--;
        }
    }
    return 0;
}