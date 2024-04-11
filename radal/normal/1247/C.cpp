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
const long long int N=1e6+20,mod = 1e9+7,inf=1e12,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
string binary(ll n){
    string s = "";
    while (n){
        if (n%2) s = '1'+s;
        else s =  '0'+s;
        n/=2;
    }
    return s;
}
int main(){
    ll n,p;
    cin >> n >> p;
    if (n <= p){
        cout << -1;
        return 0;
    }
    rep(x,1,10000000){
        if (p*x >= n) break;
        string s = binary(n-p*x);
        int cnt = 0,sz = s.size();
        rep(i,0,sz) if (s[i] == '1') cnt++;

        if (cnt <= x && n-p*x >= x){
            //debug(x);
            cout << x << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}