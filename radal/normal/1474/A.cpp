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
const long long int N=2e5+20,mod = 1e9+7,inf=1e12,maxq = 5e5+30,maxm = 3e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        string b,a="",d = "";
        cin >> n >> b;
        a += '1';
        d += char(int(a[0])+int(b[0]) - int('0'));
        rep(i,1,n){
            char c = char(int(b[i])-int('0')+int('1'));
            if (c != d[i-1]){
                a+='1';
                d += c;
            }
            else{
                a+='0';
                d += b[i];
            }
        }
        cout << a << endl;
   //     debug(d);
    }
    return 0;
}