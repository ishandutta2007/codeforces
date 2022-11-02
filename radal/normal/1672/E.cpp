#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 4e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
int main(){
//    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int l = 0,r = 2001*n,m,ans = inf;
    while(r-l > 1){
        m = (l+r) >> 1;
        cout << "? " << m << endl;
        int x;
        cin >> x;
        if (x) ans = min(1ll*ans,1ll*m*x);
        if (x == 1) r = m;
        else l = m;
    }
    rep(i,2,n+1){
        int len = r/i;
        cout << "? " << len << endl;
        int x;
        cin >> x;
        if (x == 0) break;
        ans = min(1ll*ans,1ll*x*len);
    }
    cout << "! " << ans;
}