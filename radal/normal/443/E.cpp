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
const int N = 5e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
inline int mkay(int x,int y){
    if (x+y < mod) return x+y;
    return x+y-mod;
}
bool mark[N];
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,sz = 0;
    cin >> n;
    vector<int> ve;
    ll ans = 0;
    rep(i,1,n+1){
        cin >> a[i];
        while (sz > 1 && ve[sz-1] <= a[i] && ve[sz-1] <= ve[sz-2]){
            ans += min(a[i],ve[sz-2]);
            ve.pop_back();
            sz--;
        }
        ve.pb(a[i]);
        sz++;
    }
    sort(ve.begin(),ve.end());
    rep(i,0,sz-2) ans += ve[i];
    cout << ans;
}