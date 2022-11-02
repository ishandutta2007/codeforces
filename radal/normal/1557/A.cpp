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
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,maxm = (1 << 18);
long double a[N],pre[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n){
            cin >> a[i];
        }
        sort(a,a+n);
        rep(i,0,n){
            if (!i) pre[i] = a[i];
            else pre[i] = pre[i-1]+a[i];
        }
        long double ans=-inf;
        rep(i,1,n){
            ans = max(ans,pre[i-1]/i+(pre[n-1]-pre[i-1])/(n-i));
        }
        cout << setprecision(7) << fixed << ans << endl;

    }
    return 0;
}