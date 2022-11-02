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
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=1e5+10,mod = 2e18,inf=1e18;
const long double eps = 0.0001;
ll poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    r *= r;
    r %= mod;
    return ((k%2) ? (r*a)%mod : r);
}
ll a[N];
int b[N];
int main(){
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        rep(i,0,m) b[i] = 0;
        rep(i,0,n){
            cin >> a[i];
            b[a[i]%m]++;
        }
        int cnt = 0;
        if (b[0]) cnt++;
        rep(i,1,m){
            if (!b[i]) continue;
            if (b[i] == b[m-i]){
                b[i] = 0;
                b[m-i] = 0;
                cnt++;
                continue;
            }
            if (b[i] < b[m-i]) swap(b[i],b[m-i]);
            b[i] = b[i] - b[m-i]-1;
            b[m-i] = 0;
            cnt += b[i]+1;
            b[i] = 0;
        }
        cout << cnt << endl;
    }
}