#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,ll> pll;
const long long int N=1e2+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b& 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
ll n,m,a[N],b[N],dp[N][N],vis[N][N];
ll solver(int p1,int p2){
    if (p1 == n && p2 == m) return 0;
    if (p1 == n){
        if (vis[p1][p2+1] == -1){
            dp[p1][p2+1] = solver(p1,p2+1);
            vis[p1][p2+1] = 1;
        }
        return max(b[p2],b[p2] + dp[p1][p2+1]);
    }
    if (p2 == m){
        if (vis[p1+1][p2] == -1){
            dp[p1+1][p2] = solver(p1+1,p2);
            vis[p1+1][p2] = 1;
        }
        return max(a[p1],a[p1] + dp[p1+1][p2]);
    }
    if (vis[p1+1][p2] == -1){
        dp[p1+1][p2] = solver(p1+1,p2);
        vis[p1+1][p2] = 1;
    }
    if (vis[p1][p2+1] == -1){
        dp[p1][p2+1] = solver(p1,p2+1);
        vis[p1][p2+1] = 1;
    }
    return max(max(a[p1],a[p1]+dp[p1+1][p2]),max(b[p2],b[p2]+dp[p1][p2+1]));
}
int main(){
    int T;
    cin >> T;
    while (T--){
        memset(vis,-1,sizeof vis);
        cin >> n;
        rep(i,0,n) cin >> a[i];
        cin >> m;
        rep(i,0,m) cin >> b[i];
        cout << max(a[0]-a[0],solver(0,0)) << endl;
    //    debug(solver(1,0));
    }
    return 0;
}