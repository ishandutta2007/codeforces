#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <memory.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int inf = 1000000000;
const int N = 111;

int n, m;
int s[N];
string what[N];
int who[N];
int dp[22][1 << 20];

int main() {
  // freopen("input.txt", "r", stdin);
  
  cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    sort(s, s + n);
    int sz = min(20, n);
    for (int i =0; i < sz; i++)
      s[sz - i - 1] = s[n -1 - i];
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> what[i];
      cin >> who[i];
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < 1 << sz; j++)
        dp[i][j] = inf;
    }
    for (int j = 0; j < 1 << sz; j++)
      dp[m][j] = 0;
    for (int i = m - 1; i >= 0; i--)
      for (int st = 0; st < 1 << sz; st++) {
        if (what[i]=="p") {
          for (int whoP = sz - 1; whoP >= 0; whoP--)
            if (((1 << whoP) & st) == 0) {
              int nextSt = st | (1 << whoP);
              int now = dp[i + 1][nextSt];
              if (who[i] == 1)
                now += s[whoP];
              else
                now -= s[whoP];
              if (dp[i][st] == inf) {
                dp[i][st] = now;
              } else {
                if (who[i] == 1) {
                  dp[i][st] = max(dp[i][st], now);
                } else {
                  dp[i][st] = min(dp[i][st], now);
                }
              }
              break;
            }
        } else {
          dp[i][st] = dp[i + 1][st];
          for (int whoP = sz - 1; whoP >= 0; whoP--)
            if (((1 << whoP) & st) == 0) {
              int nextSt = st | (1 << whoP);
              int now = dp[i + 1][nextSt];
              if (dp[i][st] == inf) {
                dp[i][st] = now;
              } else {
                if (who[i] == 1) {
                  dp[i][st] = max(dp[i][st], now);
                } else {
                  dp[i][st] = min(dp[i][st], now);
                }
              }
            }
        }
      }
    cout << dp[0][0];

  return 0;
}