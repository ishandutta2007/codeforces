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
const long long int N=1e6+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int a[N],b[N];
int main(){
    //ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
       int n;
       cin >> n;
       string s1,s2;
       cin >> s1 >> s2;
       rep(i,0,n){
           a[i] = int(s1[i])-int('0');
           b[i] = int(s2[i])-int('0');
       }
       //sort(a,a+n);
       //sort(b,b+n);
       bool f = 0;
       int t1=0,t2=0;
       repr(i,n-1,0){
           if (a[i] > b[i]) t1++;
           if (b[i] > a[i]) t2++;
       }
       if (t1 > t2) cout << "RED" << endl;
       else if (t1 == t2) cout << "EQUAL" << endl;
       else cout << "BLUE" << endl;
        //if (!f) cout << "EQUAL" << endl;
    }
    return 0;
}