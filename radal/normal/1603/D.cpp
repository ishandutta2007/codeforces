#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
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
const long long int N = 1e5+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 5e3+10;
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
int f(int l,int r){
    int ans = 0;
    rep(i,l,r+1){
        rep(j,i,r+1){
            if (gcd(i,j) >= l) ans++;
        }
    }
    return ans;
}
ll dp[N][20];
vector<int> tajz[N],p;
bool mark[N];
ll cnt[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    rep(i,1,N){
        if (!mark[i]) p.pb(i);
        for (int j = 1; j*i < N; j++){
            tajz[j*i].pb(i);
            mark[j*i] = 1;
        }
        dp[i][1] = 1ll*i*(i+1)/2;
    }
    rep(k,2,20){
        dp[k][k] = k;
        int l = k-1;
        cnt[k] = 1;
        ll cur = 1;
        rep(i,k+1,N){
            for (int u : tajz[i]){
                if (u <= l) continue;
                rep(v,1,i+1){
                    if (v*u > i) break;
                    if (gcd(i,v*u) != u) continue;
                    cnt[u]++;
                    cur++;
                }
            }
            while (l < i){
                ll o = 0;
                bool f = 0;
                rep(j,1,2000){
                    o += cnt[l+j];
                    if (cur+dp[l][k-1] >= dp[l+j][k-1]+cur-o){
                        cur -= o;
                        l += j;
                        f = 1;
                        break;
                    }
                }
                if (!f) break;
            }
            dp[i][k] = dp[l][k-1]+cur;
        }
        memset(cnt,0,sizeof cnt);
    }
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        if (k >= 20){
            cout << n << endl;
            continue;
        }
        cout << dp[n][k] << endl;

    }
}