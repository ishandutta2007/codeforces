#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 2e4+20,mod = 1e9+7,inf = 1e9+10;
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
int pre[1010][N];
int a[1010];
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int n;
   cin >> n;
   rep(i,1,n+1) cin >> a[i];
   pre[0][10000] = 1;
   int ans = 0;
   rep(i,1,n+1){
       rep(j,0,N){
           if (j < a[i]){
               pre[i][j] = pre[i-1][j+a[i]];
               continue;
           }
           if (j+a[i] >= N){
               pre[i][j] = pre[i-1][j-a[i]];
               continue;
           }
           pre[i][j] = mkay(pre[i-1][j-a[i]],pre[i-1][j+a[i]]);
       }
       ans = mkay(pre[i][10000],ans);
       pre[i][10000]++;
       if (pre[i][10000] == mod) pre[i][10000] -= mod;
   }
   cout << ans;
   return 0;
}