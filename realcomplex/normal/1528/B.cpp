#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
const int MOD = 998244353;

int dp[N * 2];

int main(){
    fastIO;
    dp[0]=1;
    int n;
    cin >> n;
    int rem;
    int pf = 0;
    for(int s = 2; s <= n * 2; s += 2){
        for(int x = s; x <= n * 2; x += s){
            dp[x] ++ ;
        }

        dp[s] = (dp[s] + pf) % MOD;
        pf = (pf + dp[s]) % MOD;
    }
    cout << dp[n * 2] << "\n";
    return 0;
}