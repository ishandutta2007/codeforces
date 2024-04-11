#include <bits/stdc++.h>
//#pragma GCC optimize("O3")
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
const long long int N = 3e2+20,mod = 1e9+7,inf = 1e9+10,sq = 32000;
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
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1; 
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        ll cost = 0;
        int ans = inf;
        int m = 2*n;
        rep(i,0,m){
           rep(j,0,m){
                int x;
                cin >> x;
                if (i >= n && j >= n) cost += x;
                if ((i == 0 || i == n-1) && (j == n || j == m-1)) ans = min(ans,x);
                if ((i == n || i == m-1) && (j == n-1 || !j)) ans = min(ans,x);
            }
        }
        cost += ans;
        cout << cost << endl;
    }
    return 0 ;
}