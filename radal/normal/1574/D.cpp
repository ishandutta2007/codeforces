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
const ll N = 2e5+20,mod = 1e9+7,inf = 2e18;
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    int r = poww(a,k/2);
    return 1ll*r*r%mod*poww(a,k&1)%mod;
}
inline int mkay(int a,int b){
    if (a+b < mod) return a+b;
    return a+b-mod;
}
int n,m;
int c[N],hsh[N][15],pre[N];
ll dp[15][N];
pll par[15][N];
vector<int> a[N];
vector<int> b[N];
bool cmp(vector<int>& v,vector<int>& d){
    repr(i,n-1,0){
        if (v[i] > d[i]) return 0;
        if (v[i] < d[i]) return 1;
    }
    return 0;
}
void f(int i,int r){
    if (r < 0 || i < 0) return;
    if (dp[i][r] != -1) return;
    dp[i][r] = -inf;
    par[i][r] = {-1,-1};
    int p = r,x = c[i];
    while (p >= 0 && x >= 1){
        if (b[p][i] != x){
            if (i && dp[i][r] < a[i][x-1]+pre[i-1]){
                par[i][r] = {x,m};
                dp[i][r] = a[i][x-1]+pre[i-1];
            }
            else if (!i && a[i][x-1] > dp[i][r]){
                dp[i][r] = a[i][x-1];
                par[i][r] = {x,-1};
            }
            break;
        }
        if (i){
            f(i-1,p);
            if (dp[i-1][p]+a[i][x-1] > dp[i][r]){
                dp[i][r] = a[i][x-1]+dp[i-1][p];
                par[i][r] = {x,p};
            }
        }
        while (p >= 0 && hsh[p][i+1] == hsh[r][i+1] && b[p][i] == x) p--;
        if (p < 0 || hsh[p][i+1] != hsh[r][i+1]){
            x--;
            if (x >= 1){
                if (!i){
                    if (a[i][x-1] > dp[i][r]){
                        dp[i][r] = a[i][x-1];
                        par[i][r] = {x,-1};
                    }
                }
                else{
                    if (a[i][x-1]+pre[i-1] > dp[i][r]){
                        dp[i][r] = a[i][x-1]+pre[i-1];
                        par[i][r] = {x,m};
                    }
                }
            }
            break;
        }
        x--;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n;
    rep(i,0,n){
        cin >> c[i];
        a[i].reserve(c[i]);
        rep(j,0,c[i]){
            int x;
            cin >> x;
            a[i].pb(x);
        }
        if (i) pre[i] = pre[i-1]+a[i][c[i]-1];
        else pre[i] = a[i][c[i]-1];
    }
    cin >> m;
    if (!m){
        rep(i,0,n) cout << c[i] << ' ';
        return 0;
    }
    rep(i,0,m){
        rep(j,0,n){
            int x;
            cin >> x;
            b[i].pb(x);
        }
    }
    sort(b,b+m,cmp);
    rep(i,0,m){
        repr(j,n-1,0){
            hsh[i][j] = mkay(1ll*hsh[i][j+1]*987654321%mod,b[i][j]);
        }
    }
    f(n-1,m-1);
    int i = n-1,r = m-1;
    vector<int> ve;
    while (r != -1){
        ve.pb(par[i][r].X);
        r = par[i][r].Y;
        if (r == m){
            repr(j,i-1,0) ve.pb(c[j]);
            break;
        }
        i--;
    }

    repr(i,n-1,0) cout << ve[i] << ' ';
}