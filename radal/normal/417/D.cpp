#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e2+10,mod = 1e9+7,inf=1e18,dlt = 12251,maxm = (1 << 20)+2;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1)%mod;
}
ll dp[2][maxm],dp2[2][maxm];
pair<pll,int> a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,b;
    cin >> n >> m >> b;
    rep(i,0,n){
        int cnt;
        cin >> a[i].X.Y >> a[i].X.X >> cnt;
        rep(j,0,cnt){
            int ind;
            cin >> ind;
            a[i].Y += (1 << (ind-1));
        }
    }
    sort(a,a+n);
    int g = (1 << m);
    rep(i,1,g){
        if ((i&a[0].Y) == i){
            dp[1][i] = a[0].X.Y+1ll*a[0].X.X*b;
            dp2[1][i] = a[0].X.Y;
        }
        else{
            dp[1][i] = 4e18;
            dp2[1][i] = 4e18;
        }
    }
    dp[1][0] = 0;
    dp2[1][0] = 0;
    rep(i,1,n){
        rep(j,1,g){
            dp[0][j] = dp[1][j];
            dp2[0][j] = dp2[1][j];
        }
        dp[0][0] = 0;
        dp2[0][0] = 0;
        rep(j,1,g){
            ll val = 1ll*a[i].X.X*b+a[i].X.Y+dp2[0][(j^a[i].Y)&j];
            if (val < dp[1][j]) dp[1][j] = val;
            val -= 1ll*b*a[i].X.X;
            if (val < dp2[1][j]) dp2[1][j] = val;
        }
    }
    if (dp[1][g-1] > 2e18){
        cout << -1;
        return 0;
    }
    cout << dp[1][g-1];
    return 0;
}