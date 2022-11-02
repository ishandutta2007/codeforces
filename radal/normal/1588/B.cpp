#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e3+20,mod = 1e9+7,inf = 1e9+10,lg = 18;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k /= 2;
    } 
    return z; 
}
void solve(){
    int n;
    cin >> n;
    ll i,j,k;
    int cnt = 1;
    ll tot;
    cout << "? " << 1 << ' ' << n << endl;
    cin >> tot;
    ll l = 1, r = n,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        ll x;
        if(cnt == 39) assert(0);
        cout << "? " << 1 << ' ' << m << endl;
        cin >> x;
        cnt++;
        if (!x) l = m;
        else r = m;
    }
    i = l;
    cout << "? " << i+1 << ' ' << n << endl;
    ll x;
    cin >> x;
    j = tot-x+1+i;
    tot -= (j-i)*(j-i-1)/2;
    l = j+1;
    tot *= 2;
    r = n+1;
    while (r-l > 1){
        m = (l+r) >> 1;
        if ((m-j)*(m-j+1) > tot) r = m;
        else l = m;
    }
    k = l;
    cout << "! " << i << ' ' << j << ' ' << k << endl;
}
int main(){
//    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}