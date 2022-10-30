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
const long long int N = 3e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
int a[N],b[N];
int pre[N],dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,63,sizeof dp);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        b[i] = a[i]-i;
    }
    dp[0] = -inf;
    rep(i,0,n){
        int ind = upper_bound(dp,dp+n+1,b[i])-dp;
        dp[ind] = b[i];
        pre[i] = ind;
    }
    memset(dp,63,sizeof dp);
    dp[0] = -inf;
    int ans = n-1,mx = 0;
    repr(i,n-1,1){
        int ind = upper_bound(dp,dp+n+1,-b[i-1])-dp;
        ans = min(ans,n-ind-pre[i-1]); 
        ind = upper_bound(dp,dp+n+1,-b[i]-1)-dp;
        dp[ind] = -b[i]-1;
        mx = max(mx,ind);
    }
    ans = min(ans,n-mx-1);
    cout << ans;

}