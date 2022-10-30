#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+30,mod = 1e9+7,inf=1e9;
int a[N];
long double dp[N][2];
int n;
long double check(long double x){
    long double ans=0;
    if (a[0]-x <= 0) dp[0][0] = a[0]-x;
    else dp[0][0] = 0;
    if (a[0]-x >= 0) dp[0][1] = a[0]-x;
    else dp[0][1] = 0;
    if (abs(dp[0][1]) > abs(dp[0][0])) ans = abs(dp[0][1]);
    else ans = abs(dp[0][0]);
    rep(i,1,n){
       // debug(a[1]);
        dp[i][0] = min(x-x,dp[i-1][0]+a[i]-x);
        dp[i][1] = max(x-x,dp[i-1][1]+a[i]-x);
        ans = max(ans,max(abs(dp[i][0]),abs(dp[i][1])));
       // debug(a[i]);
    }
    return ans;
}
long double tern(long double l,long double r){
    long double m1,m2;
    rep(i,0,400){
        m1 = (2*l+r)/3;
        m2 = (2*r+l)/3;
        if (check(m1) > check(m2)) l = m1;
        else r = m2;
    }
    return l;
}
int main(){
    //ios :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    rep(i,0,n) cin >> a[i];
    //check(2);
    cout << setprecision(6) << fixed << check(tern(-1e8,1e8)) << endl;
}