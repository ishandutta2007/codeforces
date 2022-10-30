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
typedef long double ld;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 5e3+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 1e3+10;
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
bool mark[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T; 
    while (T--){
        int n;
        string s;
        cin >> n >> s;
        int ans = inf;
        rep(i,0,n){
            int R = min(i+11,n);
            int a = 0,b = 0,c = 0;
            rep(j,i,R){
                if (s[j] == 'a') a++;
                if(s[j] == 'b') b++;
                if (s[j] == 'c') c++;
                if (a >= 2 && a > max(b,c)) ans = min(ans,j-i+1);
            }
        }
        if (ans == inf) cout << -1 << endl;
        else cout << ans << endl;
    }
}