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
typedef pair<long double,long double> pld;
const long long int N = 3e5+10,mod = 1e9+7,inf = 1e9,sq = 65,fx = 98765431;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T=  1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        bool f = 0;
        rep(i,0,n){
            cin >> a[i];
            if (f) continue;
            bool F = 0;
            repr(j,i+2,2){
                if(a[i]%j !=0){
                    F = 1;
                    break;
                }
            }
            if (!F) f = 1;
        }
        cout << ((f) ? "NO" : "YES") << endl;
    }

}