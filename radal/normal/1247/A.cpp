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
const long long int N=1e3+20,mod = 1e9+7,inf=1e12,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    //cin >> T;
    T = 1;
    while (T--){
        int da,db;
        cin >> da >> db;
        if (db == 1 && da == 9){
            cout << da << ' ' << db << 0;
            return 0;
        }
        if (db < da || db-da > 1){
            cout << -1;
            return 0;
        }
        if (da == db){
            cout << da << 0 << ' ' << db << 1 << endl;
            return 0;
        }
        cout << da << ' ' << db;
    }
    return 0;
}