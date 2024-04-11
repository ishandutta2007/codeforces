#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=1e6+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 524288;
ll a[N];
int main(){
    int T=1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        ll ans=0;
        rep(i,1,n+1) cin >> a[i];
        rep(i,1,n+1){
            int r = (a[i]-i%a[i])%a[i];
            rep(k,0,n+1){
                if (k*a[i]+r > n) break;
                if (k*a[i]+r == i) continue;
                if (a[k*a[i]+r]*a[i] == i+k*a[i]+r) ans++;
            }
        }
        cout << ans/2 << endl;
    }
}