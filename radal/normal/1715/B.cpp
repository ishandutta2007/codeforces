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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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

ll a[N];

void solve(){
    ll n,k,b,s;
    cin >> n >> k >> b >> s;
    rep(i,0,n) a[i] = 0;
    if (b*k > s || b*k+(k-1)*n < s){
        cout << -1 << endl;
        return;
    }
    a[0] = b*k;
    s -= b*k;
    rep(i,0,n){
        if (s < k){
            a[i] += s;
            break;
        }
        a[i] += k-1;
        s -= (k-1);
    }
    rep(i,0,n) cout << a[i] << ' ';
    cout << endl;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}