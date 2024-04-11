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
constexpr int N = 3e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int w,h;
        cin >> w >> h;
        vector<int> ve;
        ve.pb(1);
        int g = gcd(w-1,h-1);
        for (int i = 1; i*i <= g; i++){
            if (g%i) continue;
            ve.pb(i);
            ve.pb(g/i);
        }
        g = gcd(w-2,h);
        for (int i =  1; i*i <= g; i++){
            if (g%i) continue;
            ve.pb(i);
            ve.pb(g/i);
        }
        g = gcd(w,h-2);
        for (int i = 1; i*i <= g; i++){
            if (g%i) continue;
            ve.pb(i);
            ve.pb(g/i);
        }
        if ((h&1) == 0 && (w&1)){
            ve.pb(2);
        }
        else if ((h&1) && (w&1) == 0){
            ve.pb(2);
        }
        sort(ve.begin(),ve.end());
        ve.resize(unique(all(ve))-ve.begin());
        cout << ve.size() << ' ';
        for (int u : ve) cout << u << ' ';
        cout << endl;
    }
}