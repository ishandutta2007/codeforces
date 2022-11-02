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
const long long int N=1e5+10,mod = 17,inf=4e18,maxm = 1000;
const long double eps = 0.0001;
ll poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    long long ans = poww(a,k/2);
    ans *= ans;
    ans %= mod;
    if (k%2){
        ans*=a;
        ans %= mod;
    }
    return ans;
}
ld a[N],b[N];
int main(){
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        int n,ind1=0,ind2 = 0;
        cin >> n;
        rep(i,0,2*n){
            int x,y;
            cin >> x >> y;
            if (!x){
                a[ind1] = abs(y);
                ind1++;
            }
            else{
                b[ind2] = abs(x);
                ind2++;
            }
        }
        sort(a,a+n);
        sort(b,b+n);
        ld ans = 0;
        rep(i,0,n){
            ans += sqrt(b[i]*b[i]+a[i]*a[i]);
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}