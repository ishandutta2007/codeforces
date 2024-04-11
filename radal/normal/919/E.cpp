#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 1e6+20,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int p){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    } 
    return z; 
}
int pw[N],inv[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    ll x,p,a,b,ans = 0;
    cin >> a >> b >> p >> x;
    pw[0] = 1;
    inv[0] = 1;
    rep(i,1,p-1){
        pw[i] = 1ll*pw[i-1]*a%p;
        inv[i] = poww(pw[i],p-2,p);
    }
    int m1 = 1,m2 = -1;
    rep(i,0,p-1){
        int a1 = b*inv[i]%p;
        ll cal = a1*(p-1)*m2+i*p*m1;
        cal %= p*(p-1);
        if (cal < 0) cal += p*(p-1);
        if (cal > x) continue;
        ans += (x-cal+p*(p-1))/p/(p-1);
    }
    cout << ans;
    return 0;
}