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
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=(1<<23)+20,mod = 1e9+7,inf=2e9,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
map<int,int> mp;
int a[30];
vector<int> dp[23];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        dp[i].resize((1<<(i+1)));
        mp[a[i]]=i;
        fill(dp[i].begin(),dp[i].end(),inf);
    }
    if (n == 1){
        cout << 1;
        return 0;
    }
    dp[0][1] = 1;
    int ans = inf;
    rep(i,1,n){
        int y = (1 << i);
        rep(j,0,y){
            int x = j+(1 << i),pc = __builtin_popcount(x);;
            if (pc >= ans) continue;
            bool f = 0;
            rep(k,0,i){
                if (mp.find(a[i]-a[k]) == mp.end()) continue;
                int ind = mp[a[i]-a[k]];
                if (ind >= i) continue;
                int u = (1 << ind),v = (1<<k);
                if (ind == k){
                    if (!(j&u)) dp[i][x] = min(dp[i-1][j+u],dp[i][x]);
                    else f = 1;
                    continue;
                }
                if (!(j&u) && !(j&v)) continue;
                if (!(j&u) && dp[i-1][j+u] < dp[i][x]) dp[i][x] = dp[i-1][j+u];
                if (!(j&v) && dp[i-1][j+v] < dp[i][x]) dp[i][x] = dp[i-1][j+v];
                if ((j&v) && (j&u)) f = 1;
                if(dp[i][x] <= pc){
                    dp[i][x] = pc;
                    f = 0;
                    break;
                }
            }
            if (f){
                rep(k,0,i){
                    int u = (1<<k);
                    if(!(j&u) && dp[i-1][j+u] < dp[i][x]){
                        dp[i][x] = dp[i-1][j+u];
                        if (dp[i][x] <= pc){
                            dp[i][x] = pc;
                            break;
                        }
                    }
                }
                if (dp[i-1][j] <dp[i][x]){
                    dp[i][x] = dp[i-1][j];
                    if (dp[i][x] < pc) dp[i][x] = pc;
                }
            }
            if (i == n-1 &&  dp[i][x] < ans) ans = dp[i][x];
        }
    }
    if (ans == inf) cout << -1;
    else cout << ans;
}