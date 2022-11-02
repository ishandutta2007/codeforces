#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
//#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 1e5+5,mod = 1e9+7,inf = 1e9+10;
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
pll p[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    ll s = 0;
    int n;
    cin >> n;
    rep(i,0,n){
        int x;
        cin >> x;
        s += x;
    }
    int m;
    cin >> m;
    rep(i,0,m){
        cin >> p[i].X >> p[i].Y;
    }
    if (p[m-1].Y < s){
        cout << -1;
        return 0;
    }
    rep(i,0,m){
        if (p[i].X >= s){
            cout << p[i].X;
            return 0;
        }
        if (p[i].Y >= s){
            cout << s;
            return 0;
        }
    }
    return 0;
}