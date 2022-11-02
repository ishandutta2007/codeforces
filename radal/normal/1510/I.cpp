#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
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
constexpr ll N = 1e3+10,mod = 998244353,inf = 1e9+10;
const ld eps = 0.001;
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
ld powld(ld d,int k){
    if (k < 0) return 0;
    ld z = 1;
    while (k){
        if (k&1) z = z*d;
        d = d*d;
        k /= 2;
    }
    return z;
}
int bad[N];
int main(){
    //ios :: sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n,m;
    cin >> n >> m;
    ld d = 0.7;
    rep(i,0,m){
        string s;
        cin >> s;
        int mi = i+10;
        ld cnt[2] = {0,0};
        rep(j,0,n) mi = min(mi,bad[j]);
        rep(j,0,n){
            if (s[j] == '0')
                cnt[0] += powld(d,bad[j]-mi);
            else
                cnt[1] += powld(d,bad[j]-mi);
        }
		ld p = rng()%100000/100000.0;
        if (p <= cnt[1]/(cnt[0]+cnt[1])) cout << 1 << endl;
        else cout << 0 << endl;
        char x;
        cin >> x;
        rep(j,0,n) if (s[j] != x) bad[j]++;
    }
    return 0;
}