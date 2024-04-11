#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
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
const long long int N = 7e5+20,mod = 1e9+7,inf = 1e18,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int n = s.size();
        int mx = -1;
        rep(i,0,n-1){
            int x = s[i]-'0';
            int y = s[i+1]-'0';
            if (x+y >= 10) mx = i;
        }
        if (mx == -1){
            int x = s[0]-'0';
            int y = s[1]-'0';
            cout << x+y;
            rep(i,2,n) cout << s[i];
            cout << endl;
        }
        else{
            rep(i,0,mx) cout << s[i];
            int x = s[mx]-'0',y = s[mx+1]-'0';
            cout << x+y;
            rep(i,mx+2,n) cout << s[i];
            cout << endl;
        }
    }
}