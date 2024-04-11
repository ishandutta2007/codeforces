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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
pll a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i].X >> a[i].Y;
        bool f = 1;
        if (a[0].Y > a[0].X) f = 0; 
        rep(i,1,n){
            if (a[i].X < a[i-1].X || a[i].Y < a[i-1].Y || a[i].Y-a[i-1].Y > a[i].X - a[i-1].X) f = 0;
        }
        f ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}