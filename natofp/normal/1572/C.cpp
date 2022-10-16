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

const int N = 3005;
int nxt[N];
int dp[N][N];
int a[N];
int n;
int last[N];

void solve(){
    cin >> n;
    int xd = n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] == a[i - 1]){
            i--; n--;
        }
    }

    for(int i=1;i<=xd;i++) last[i] = n + 1;
    for(int i=n;i>=1;i--){
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }

    for(int i=1;i<=n;i++) dp[i][i] = 0;
    for(int len=2;len<=n;len++){
        for(int s=1;s<=n;s++){
            int e = s + len - 1;
            if(e > n) break;
            dp[s][e] = dp[s + 1][e] + 1;
            int p = nxt[s];
            while(p <= e){
                dp[s][e] = min(dp[s][e], dp[s + 1][p - 1] + 1 + dp[p][e]);
                p = nxt[p];
            }
        }
    }
    cout << dp[1][n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}