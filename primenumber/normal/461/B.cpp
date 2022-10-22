#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <cmath>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;

int aw[100001];

int search(vector<vector<int>>& g, vecint& clr, int i, int nac, vector<vector<int64_t>>& dp) {
  if (dp[i][nac] >= 0) return dp[i][nac];
  if (clr[i] == 1) {
    int64_t res = 1;
    for(int ch:g[i]) {
      res *= search(g, clr, ch, 1, dp);
      res %= 1000000007;
    }
    return dp[i][nac] = res;
  } else if (aw[i]) {
    return dp[i][nac] = 1;
  } else {
    if (nac) {
      int64_t res = 1;
      for (int ch:g[i]) {
        if (aw[ch]) continue;
        res *= search(g, clr, ch, 1, dp);
        res %= 1000000007;
      }
      res += search(g, clr, i, 0, dp);
      res %= 1000000007;
      return dp[i][nac] = res;
    } else {
      int n=g[i].size();
      vector<int64_t> cac(n, 1);
      vector<int64_t> tm(n, 1);
      vector<int64_t> tm_r(n, 1);
      REP(j,n) {
        cac[j] = search(g,clr,g[i][j],1,dp);
      }
      REP(j,n-1) {
        tm[j+1] = tm[j] * cac[j];
        tm[j+1] %= 1000000007;
        tm_r[n-j-2] = tm_r[n-j-1] * cac[n-j-1];
        tm_r[n-j-2] %= 1000000007;
      }
      int64_t res = 0;
      REP(j,n) {
        if (aw[g[i][j]]) continue;
        int64_t pres = search(g, clr, g[i][j],0,dp);
        pres *= tm[j];
        pres %= 1000000007;
        pres *= tm_r[j];
        pres %= 1000000007;
        res += pres;
        res %= 1000000007;
      }
      return dp[i][nac] = res;
    }
  }
}

void saw(int i, vector<vecint>& g, vecint& clr) {
  aw[i] = 1 - clr[i];
  for (int ch:g[i]) {
    saw(ch, g, clr);
    if (aw[ch] == 0)
      aw[i] = 0;
  }
}

int main()
{
  int n;
  cin>>n;
  vector<vecint> ch(n);
  REP(i,n-1) {
    int p;
    cin>>p;
    ch[p].push_back(i+1);
  }
  vecint clr(n);
  REP(i,n) cin>>clr[i];
  saw(0,ch,clr);
  vector<vector<int64_t>> dp(n, vector<int64_t>(2, -1));
  cout << search(ch, clr, 0, 0, dp) << endl;
  return 0;
}