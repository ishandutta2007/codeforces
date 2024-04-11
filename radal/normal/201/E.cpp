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
typedef pair<int,int> pll;
const long long int N=20,mod = 1e9+7,inf=2e18,dlt = 12251,maxm = (1 << 18)+2;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1)%mod;
}
int n,m;
ll c(int i,ll r){
    __int128 a = 1;
    repr(j,r,r-i+1) a*=j;
    rep(j,2,i+1) a/=j;
    if (a >= inf) return inf;
    return a;
}
bool check(int r){
    ll ans = 0;
    int i = 0;
    ll p = 0,k=1;
    while (i <= r && (p+k*i+r-1)/r <= m){
        ans += k;
        p += k*i;
        k = c(i+1,r);
        i++;
    }
    if (i < r) return ((ans+(m-p/r)*r/i) >= n);
    else return (ans >= n);
}
int bs(int l,int r){
    int mid;
    while (r-l > 1){
        mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return r;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> m;
        if (n == 1){
            cout << 0 << endl;
            continue;
        }
        cout << bs(0,n+1) << endl;
    }
    return 0;
}