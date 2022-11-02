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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e16;
const long double eps = 0.0001;
ll a[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,d;
        cin >> n >> d;
        rep(i,0,n) cin >> a[i];
        sort(a,a+n);
        if (a[n-1] > d && a[0]+a[1] > d) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}