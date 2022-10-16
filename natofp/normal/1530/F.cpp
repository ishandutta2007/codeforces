#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int mod = 31607;
const int nax = 21;

ll pp(ll a, ll b){
    if(b==0) return 1;
    ll ans = pp(a,b/2);
    ans*=ans;
    ans %= mod;
    if(b&1){
        ans *= a;
        ans %= mod;
    }
    return ans;
}

int INW[10005];

int po[nax * nax];

void prep(){
    INW[0] = 0;
    for(int i=1;i<10005;i++){
        INW[i] = pp(i, mod - 2);
    }
    po[0] = 1;
    for(int i=1;i<nax*nax;i++){
        po[i] = po[i - 1] * 10000;
        po[i] %= mod;
    }
}

int a[nax][nax];
int n;

int dp[nax][2];
int ilo[nax][1 << nax];

int hehe = 0;

void solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    if(n&1){
        hehe = pp(a[n/2][n/2], mod - 2);
    }
    for(int i=0;i<n;i++){
        ilo[i][0] = 1;
        for(int j=1;j<(1<<n);j++){
            for(int k=0;k<n;k++){
                if(j & (1 << k)){
                    ilo[i][j] = (ilo[i][j ^ (1 << k)] * a[i][k] % mod);
                    break;
                }
            }
        }
    }

    int wins = 0;
    int ful = (1 << n) - 1;
    for(int d=0;d<4;d++){
        for(int mask=0;mask<(1<<n);mask++){
            int ways = 1;
            for(int r=0;r<n;r++){
                ways *= ilo[r][mask];
                ways %= mod;
            }
            if(d&1){
                for(int r=0;r<n;r++){
                    if(mask & (1<<r));
                    else{
                        ways *= a[r][r];
                        ways %= mod;
                    }
                }
            }
            if(d&2){
                for(int r=0;r<n;r++){
                    if(mask & (1 << (n - 1 - r)));
                    else{
                        ways *= a[r][n - 1 - r];
                        ways %= mod;
                    }
                }
            }

            if(d==3 && (n&1) && ((mask & (1 << (n/2))) == 0)){
                ways *= hehe;
                ways %= mod;
            }

            for(int k=0;k<n;k++){
                dp[k][0] = 0; dp[k][1] = 0;
            }
            int first_row = mask;
            if(d & 1) first_row |= 1;
            if(d & 2) first_row |= (1 << (n - 1));
            dp[0][1] = ilo[0][ful ^ first_row];
            int cnt_unset = 0;
            for(int k=0;k<n;k++){
                if(first_row & (1 << k));
                else cnt_unset++;
            }
            int eldo = 0;
            for(int k=0;k<n;k++){
                if(mask & (1 << k));
                else eldo++;
            }
            dp[0][0] = po[cnt_unset];
            for(int k=0;k<n-1;k++){
                for(int j=0;j<2;j++){
                    int nxt_row = (mask);
                    int cp = eldo;
                    if(d&1) nxt_row |= (1 << (k + 1));
                    if(nxt_row != mask){
                        cp--;
                    }
                    int xd = nxt_row;
                    if(d&2) nxt_row |= (1 << (n - 1 - (k + 1)));
                    if(nxt_row != xd){
                        cp--;
                    }
                    dp[k + 1][j ^ 1] += dp[k][j] * ilo[k + 1][ful ^ nxt_row];
                    dp[k + 1][j ^ 1] %= mod;
                    dp[k + 1][j] += dp[k][j] * po[cp] % mod;
                    dp[k + 1][j] %= mod;
                }
            }
            int par = 0;
            par += ((d & 1) > 0) + ((d & 2) > 0);
            for(int k=0;k<n;k++) par += ((1 << k) & mask) > 0;
            par &= 1;
            if(par == 0){
                wins += dp[n - 1][1] * ways;
                wins %= mod;
                wins -= (dp[n - 1][0] * ways % mod);
                if(wins < 0) wins += mod;
            }
            else{
                wins += dp[n - 1][0] * ways;
                wins %= mod;
                wins -= (dp[n - 1][1] * ways % mod);
                if(wins < 0) wins += mod;
            }
        }
    }
    wins += (pp(10000, n * n) % mod);
    wins %= mod;

    wins *= pp(pp(10000, n * n), mod - 2);
    wins %= mod;
    cout << wins;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}