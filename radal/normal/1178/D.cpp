#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e6+20,mod = 998244353 ,inf = 1e9+10,maxm = (1 << 18)+10;
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
inline bool pr(int x){
    for (int i = 2; i*i <= x; i++){
        if (x%i == 0) return 0;
    }
    return 1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int m = n;
    while (!pr(m)) m++;
    cout << m << endl;
    rep(i,1,n) cout << i << ' ' << i+1 << endl;
    cout << n << ' ' << 1 << endl;
    int t = m-n;
    int po = 1;
    rep(i,0,t){
        if (po+2 <= n) cout << po << ' ' << po+2 << endl;
        else{
            if (po == n) cout << n << ' ' << 2 << endl;
            else cout << n-1 << ' ' << 1 << endl;
        }
        if ((i&1)) po += 3;
        else po++;
    }

}