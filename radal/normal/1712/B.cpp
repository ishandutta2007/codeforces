#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr long long int N = 1e3+20,mod = 1e9+7 ,inf = 1e9+10;
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
        k >>= 1;
    }
    return z;
}

int a[N];
inline void solve(){
    int n;
    cin >> n;
    if (n%2){
        cout << 1 << ' ';
        for (int i = 2; i < n; i+= 2){
            cout << i+1 << ' ' << i << ' ';
        }
        cout << endl;
        return;
    }
    
    for (int i = 1; i < n; i+= 2){
        cout << i+1 << ' ' << i << ' ';
    }
    cout << endl;
}
int main(){
    ios:: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}