#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
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
constexpr int N = 1e6+20,mod = 1e9+7,inf = 1e9+10,lg = 18;
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
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    string s,t = "";
    cin >> s;
    n = s.size();
    bool f = 0;
    rep(i,0,n){
        if (i < n-2 && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
            i += 2;
            f = 1;
            continue;
        }
        if (f) t += ' ';
        t += s[i];
        f = 0;
    }
    if (!t.empty() && t[0] == ' ') t.erase(t.begin());
    cout << t;
    return 0;
}