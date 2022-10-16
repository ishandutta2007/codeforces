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
#define mt make_tuple

using namespace std;

const int nax = 205;
ll a[nax][nax];
ll pref[nax][nax];
int n;
ll inf = 1e18;

ll ask(int lr, int hr, int lc, int hc){
    return (pref[hr][hc] - pref[lr - 1][hc] - pref[hr][lc - 1] + pref[lr - 1][lc - 1]);
}

ll dp[nax][nax];
ll opt[nax][nax];

int par[nax];

void reku(int lo, int hi, int p){
    if(lo > hi) return;
    int boss = opt[lo][hi];
    par[boss] = p;
    reku(lo, boss - 1, boss);
    reku(boss + 1, hi, boss);
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][i] = 0;
        opt[i][i] = i;
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n;i++){
            int from = i;
            int to = from + len - 1;
            if(to > n) break;
            dp[from][to] = inf;
            for(int mid=from;mid<=to;mid++){
                ll cost = dp[from][mid - 1] + dp[mid + 1][to];
                cost += ask(from, mid - 1, 1, n) - ask(from, mid - 1, from, mid - 1);
                cost += ask(mid + 1, to, 1, n) - ask(mid + 1, to, mid + 1, to);
                if(cost < dp[from][to]){
                    dp[from][to] = cost;
                    opt[from][to] = mid;
                }
            }
        }
    }
    reku(1, n, 0);
    for(int i=1;i<=n;i++) cout << par[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}