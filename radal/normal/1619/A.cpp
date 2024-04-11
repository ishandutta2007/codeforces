#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 1e4+20,mod = 1e9+7,inf = 1e9,sq = 4e7;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int n = s.size();
        string t1 = "",t2 = "";
        if (n&1){
            cout << "NO" << endl;
            continue;
        }
        rep(i,0,n/2) t1 += s[i];
        rep(i,n/2,n) t2 += s[i];
        cout << ((t1 == t2) ? "YES" : "NO") << endl;
    }
}