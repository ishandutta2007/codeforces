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
const long long int N = 1e3+20,mod = 1e9+7,inf = 2e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
pll dp[N][N][2],par[N][N][2];
int a[N][N],cnt[N][N][2];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int v = -1;
    rep(i,0,n){ 
        rep(j,0,n){
            cin >> a[i][j];
            if (!a[i][j]){
                v = i;
                a[i][j] = 10;
            }
            while ((a[i][j]&1) == 0){
                a[i][j] >>= 1;
                cnt[i][j][0]++;
            }
            while (a[i][j]%5 == 0){
                a[i][j] /= 5;
                cnt[i][j][1]++;
            }
        }
    }
    repr(i,n-1,0){
        repr(j,n-1,0){
            if (i == n-1){
                if (j == n-1){
                    dp[i][j][0] = {cnt[i][j][0],cnt[i][j][1]};
                    par[i][j][0] = {-1,-1};
                    dp[i][j][1] = {cnt[i][j][1],cnt[i][j][0]};
                    par[i][j][1] = {-1,-1};
                }
                else{
                    dp[i][j][0] = {cnt[i][j][0]+dp[i][j+1][0].X,cnt[i][j][1]+dp[i][j+1][0].Y};
                    par[i][j][0] = {i,j+1};
                    dp[i][j][1] = {cnt[i][j][1]+dp[i][j+1][1].X,cnt[i][j][0]+dp[i][j+1][1].Y};
                    par[i][j][1] = {i,j+1};
                }
                continue;
            }
            if (j == n-1 || dp[i+1][j][0] <= dp[i][j+1][0]){
                dp[i][j][0] = {cnt[i][j][0]+dp[i+1][j][0].X,cnt[i][j][1]+dp[i+1][j][0].Y};
                par[i][j][0] = {i+1,j};
            }
            else{
                dp[i][j][0] = {cnt[i][j][0]+dp[i][j+1][0].X,cnt[i][j][1]+dp[i][j+1][0].Y};
                par[i][j][0] = {i,j+1};
            }
            if (j == n-1 || dp[i+1][j][1] <= dp[i][j+1][1]){
                dp[i][j][1] = {cnt[i][j][1]+dp[i+1][j][1].X,cnt[i][j][0]+dp[i+1][j][1].Y};
                par[i][j][1] = {i+1,j};
            }
            else{
                dp[i][j][1] = {cnt[i][j][1]+dp[i][j+1][1].X,cnt[i][j][0]+dp[i][j+1][1].Y};
                par[i][j][1] = {i,j+1};
            }
        }
    }
    if (min({dp[0][0][0].X,dp[0][0][0].Y,dp[0][0][1].X,dp[0][0][1].Y}) >= 1 && v != -1){
        int x = 0,y = 0;
        cout << 1 << endl;
        while (x < v){
            cout << 'D';
            x++;
        }
        while(y < n-1){
            cout << 'R';
            y++;
        }
        while (x < n-1){
            cout << 'D';
            x++;
        }
        return 0;
    }
    if (min(dp[0][0][0].X,dp[0][0][0].Y) <= min(dp[0][0][1].X,dp[0][0][1].Y)){
        int x = 0,y = 0;
        cout << min(dp[0][0][0].X,dp[0][0][0].Y) << endl;
        while (x != n-1 || y != n-1){
            if (par[x][y][0].X != x) cout << 'D';            else cout << 'R';
            int z = x;
            x = par[x][y][0].X;
            y = par[z][y][0].Y;
        }
        return 0;
    }
    cout << min(dp[0][0][1].X,dp[0][0][1].Y) << endl;
    int x = 0,y = 0;
    while (x != n-1 || y != n-1){
        if (par[x][y][1].X != x) cout << 'D';
        else cout << 'R';
        int z = x;
        x = par[x][y][1].X;
        y = par[z][y][1].Y;
    }
    return 0;

}