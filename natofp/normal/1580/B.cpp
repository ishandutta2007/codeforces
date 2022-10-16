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

int n,m,k;
int cc;

const int nax = 101;
int binom[nax][nax];
int f[nax];

void prep(){
    int mod = cc;
    binom[0][0] = (1 % mod);
    for(int i=1;i<nax;i++){
        binom[i][0] = (1 % mod);
        for(int j=1;j<nax;j++){
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
        }
    }
    f[0] = (1 % mod);
    for(int i=1;i<nax;i++){
        ll cur = (ll)f[i - 1] * i;
        cur %= mod;
        f[i] = cur;
    }
}
int dp[nax][nax][nax]; // len, exactly j of (k - maxes)

void solve(){
    cin >> n >> m >> k >> cc;
    const int mod = cc;
    prep();
    for(int i=0;i<nax;i++) dp[0][0][i] = (1 % mod);
    for(int i=1;i<=n;i++) dp[i][0][0] = f[i];
    for(int i=1;i<nax;i++){
        for(int j=i+1;j<nax;j++) dp[i][0][j] = f[i];
    }
    for(int len=1;len<=n;len++){
        for(int j=0;j<=len;j++){
            for(int k=1;k<=len;k++){
                bool dbg = (len == 1 && j == 1 && k == 1);
                for(int pos=1;pos<=(len+1)/2;pos++){
                    int ways = (binom[len - 1][pos - 1]) * (1 + (pos * 2 - 1 != len));
                    int sum = 0;
                    for(int L=0;L<=j-(k==1);L++){
                        if(!dp[pos-1][L][k - 1]) continue;
                        sum += ((ll)dp[pos - 1][L][k - 1] * dp[len - pos][j - (k == 1) - L][k - 1]) % mod;
                        if(sum >= mod) sum -= mod;
                    }
                    dp[len][j][k] += ((ll)sum * ways) % mod;
                    dp[len][j][k] %= mod;
                }
            }
        }
    }
    cout << dp[n][k][m] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}