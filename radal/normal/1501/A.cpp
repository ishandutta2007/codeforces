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
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=1e2+10,mod = 2e18,inf=1e18;
const long double eps = 0.0001;
int a[N],b[N],t[N],ans[N],ans2[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i] >> b[i];
        rep(i,0,n) cin >> t[i];
        ans[0] = a[0]+t[0];
        ans2[0] = max(b[0],ans[0]+(b[0]-a[0])/2+(b[0]-a[0])%2);
        rep(i,1,n){
            ans[i] = ans2[i-1]+a[i]-b[i-1]+t[i];
            ans2[i] = max(b[i],ans[i]+(b[i]-a[i])/2+(b[i]-a[i])%2);
        }
        cout << ans[n-1] << endl;
    }
}