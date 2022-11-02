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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10;
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
int pr[N];
void solve(){
    int n,m,b = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    rep(i,0,n) b += (s[i] == '1');
    if (1ll*b*m%n){
        cout << -1 << endl;
        return;
    }
    int x = 1ll*b*m/n;
    if (m-x > n-b){
        cout << -1 << endl;
        return;
    }
    rep(i,0,n){
        pr[i] = (s[i] == '1');
        if (i) pr[i] += pr[i-1];
    }
    int j = -1;
    rep(i,m,n){
        if (pr[i]-pr[i-m] == x){
            j = i;
            break;
        }
    }
    if (j != -1 || pr[m-1] == x){
        cout << 1 << endl;
        if (pr[m-1] == x) j = m-1;
        cout << j-m+2 << ' ' << j+1 << endl;
        return;
    }
    cout << 2 << endl;
    rep(i,0,m-1){
        if (pr[i]+pr[n-1]-pr[n+i-m] == x){
            cout << 1 << ' ' << i+1 << endl;
            cout << n+i-m+2 << ' ' << n << endl;
            return;
        }
    }
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