#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 2e5+20,mod = 998244353,inf = 1e9+10;
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
int n,k,cnt;
int f(int x,int y){
    string s = "",t = "";
    vector<int> v1,v2;
    rep(i,0,cnt){
        v1.pb(x%k);
        v2.pb(y%k);
        x /= k;
        y /= k;
    }
    int sz = v1.size();
    repr(i,sz-1,0)
        if (v1[i] != v2[i]) 
            return sz-i;
    return 0;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int z = 1;
    while (z < n){
        cnt++;
        z *= k;
    }
    cout << cnt << endl;
    debug(z);
    rep(i,0,n)
        rep(j,i+1,n)
            cout << f(i,j) << ' ';
    return 0;
}