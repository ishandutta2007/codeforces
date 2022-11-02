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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=1e9,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int a[N],dp[N];
inline int d(int p,int q){
    return abs(p-q)+abs(a[p]-a[q]);
}
inline bool val(int p,int q,int r){
    bool f;
    f = (d(p,q) != d(p,r)+d(r,q));
    f &= (d(p,r) != d(p,q)+d(r,q));
    f &= (d(q,r) != d(p,q)+d(p,r));
    return f;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        dp[0] = 1;
        int l = 0;
        rep(i,1,n+1){
            dp[i]= dp[i-1];
            rep(j,l,i-1){
                rep(k,j+1,i){
                    if (!val(i,j,k)){
                        l = j+1;
                        break;
                    }
                }
            }
            dp[i] += i-l+1;
        }
        cout << dp[n-1] << endl;
    }
    return 0;
}