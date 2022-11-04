#include <bits/stdc++.h>

using namespace std;

const int MAXN = 6;

double prob[(1 << MAXN) + 1][(1 << MAXN) + 1];

double dp1[(1 << MAXN) + 1][MAXN + 1];
double dp2[(1 << MAXN) + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, lvl;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= (1 << n); i++) {
         for(j = 1; j <= (1 << n); j++) {
            cin >> prob[i][j];
            prob[i][j] /= 100.0;
         }
    }
    for(i = 1; i <= (1 << n); i++)
         dp1[i][0] = 1.0;
    int p = 2;
    for(lvl = 1; lvl <= n; lvl++) {
         for(i = 1; i <= (1 << n); i++) {
              j = 1;
              while(j + p - 1 < i)
                  j += p;
              int pos = j + p - 1;
              int aux = j;
              for(; j <= pos; j++)
                  if((j > (aux + pos) / 2 && i <= (aux + pos) / 2) || (j <= (aux + pos) / 2 && i > (aux + pos) / 2))
                    dp1[i][lvl] += dp1[j][lvl - 1] * dp1[i][lvl - 1] * prob[i][j];
         }
         p *= 2;
    }
    p = 2;
    double p2 = 1.0;
    for(lvl = 1; lvl <= n; lvl++) {
         for(i = 1; i <= (1 << n); i++) {
             j = 1;
             while(j + p - 1 < i)
                 j += p;
             int pos = j + p - 1;
             int aux = j;
             for(; j <= pos; j++)
                  if((j > (aux + pos) / 2 && i <= (aux + pos) / 2) || (j <= (aux + pos) / 2 && i > (aux + pos) / 2))
                     dp2[i][lvl] = max(dp2[i][lvl], dp2[i][lvl - 1] + dp2[j][lvl - 1] + dp1[i][lvl] * p2);
         }
         p2 *= 2.0;
         p *= 2;
    }
    double ans = 0.0;
    for(i = 1; i <= (1 << n); i++)
         ans = max(ans, dp2[i][n]);
    cout << setprecision(20) << ans;
    //cin.close();
    //cout.close();
    return 0;
}