#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
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
const long long int N=2e3+10,mod = 1e9+7,inf=1e18,dlt = 12251;
vector<ll> ve;
int n;
ll k;
ll po[100];
ll poww(ll i,int w){
    if(w <= 0) return 1;
    if (w==1) return i;
    ll r = poww(i,w/2);
    return r*r*poww(i,w&1);
}
void f(int s,int mx){
    if (s > mx || !n) return;
    if (n > 62 || k <= poww(2,n-2)){
        ve.pb(s);
        n--;
        f(s+1,mx);
        return;
    }
    po[1] = poww(2,n-2);
    rep(i,2,63){
        po[i] = poww(2,n-i-1)+po[i-1];
        if (k <= po[i]){
            n -= i;
            int u = min(mx,s+i-1);
            repr(j,u,s) ve.pb(j);
            k -= po[i-1];
            f(s+i,mx);
            return;
        }
    }
}
void solve(){
    cin >> n >>k;
    if (n < 63 && k > poww(2,n-1)){
        cout << -1 << endl;
        return;
    }
    f(1,n);
    for (int u : ve) cout << u << ' ';
    cout << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        ve.clear();
        solve();
    }
}