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
typedef pair<int,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    if (k > 3 || n <= 3 || k == 1){
        cout << -1;
        return 0;
    }
    if (n == 4){
        if (k == 3){
            cout << 3 << endl;
            rep(i,2,5){
                cout << i-1 << ' ' << i << endl;
            }
            return 0;
        }
        cout << -1;
        return 0;
    }
    if (k ==2){
        cout << n-3+(n-3)*(n-4)/2+3 << endl;
    }
    else{
        cout << n-3+(n-3)*(n-4)/2+2 << endl;
    }
    rep(i,2,n-1){
        cout << 1 << ' ' << i << endl;
    }
    rep(i,2,n-1){
        rep(j,i+1,n-1){
            cout << i << ' ' << j << endl;
        }
    }
    cout << n-1 << ' ' << 2 << endl;
    cout << 3 << ' ' << n << endl;
    if (k == 2){
        cout << n << ' ' << n-1 << endl;
    }
}