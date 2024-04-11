#include <bits/stdc++.h>
#define MAXN 100010
#define LOG 34

using namespace std;

struct Dp {
    long long sum;
    int val;
    int nod;
}dp[MAXN + 1][LOG + 1];


int f[MAXN + 1], w[MAXN + 1];

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, n, lg;
    long long k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> f[i];
    for(i = 0; i < n; i++)
        cin >> w[i];
    for(i = 0; i < n; i++) {
        dp[i][0].sum = w[i];
        dp[i][0].val = w[i];
        dp[i][0].nod = f[i];
    }
    for(lg = 1; (1LL << lg) <= k; lg++)
       for(i = 0; i < n; i++) {
           dp[i][lg].sum = dp[i][lg - 1].sum + dp[dp[i][lg - 1].nod][lg - 1].sum;
           dp[i][lg].val = min(dp[i][lg - 1].val, dp[dp[i][lg - 1].nod][lg - 1].val);
           dp[i][lg].nod = dp[dp[i][lg - 1].nod][lg - 1].nod;
       }
    for(i = 0; i < n; i++) {
       long long sum = 0;
       int val = (1 << 30);
       int nod = i;
       for(lg = LOG; lg >= 0; lg--)
         if(k & (1LL << lg)) {
             sum += dp[nod][lg].sum;
             val = min(val, dp[nod][lg].val);
             nod = dp[nod][lg].nod;
         }
       cout << sum << " " << val << endl;
    }
  //  cin.close();
  //  cout.close();
    return 0;
}