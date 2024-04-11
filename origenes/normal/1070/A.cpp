#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a, b, sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define mod 1000000007

int d, total, vst[555][5555], trace[555][5555][2];
queue<pair<int, int>> q;
vector<int> ans;

int main() {
  ios::sync_with_stdio(0);
  cin >> d >> total;
  q.push({0, 0});
  vst[0][0] = 1;

  while (q.size()) {
    int rem = q.front()._1, sum = q.front()._2;
    q.pop();
    //cout << rem << ' ' << sum << endl;
    REP (digit, 10) if (digit + sum <= total) {
      int nrem = (rem * 10 + digit) % d;
      if (!vst[nrem][sum + digit]) {
        vst[nrem][sum + digit] = 1;
        trace[nrem][sum + digit][0] = rem;
        trace[nrem][sum + digit][1] = sum;
        q.push({nrem, sum + digit});
      }
    }
  }

  if (!vst[0][total]) {
    cout << -1;
    return 0;
  }
  int rem = 0, sum = total;
  while (rem || sum) {
    //cout << rem << ' ' << total << endl;
    int prem = trace[rem][sum][0];
    int psum = trace[rem][sum][1];
    ans.pb(sum - psum);
    rem = prem;
    sum = psum;
  }

  reverse(all(ans));
  for (auto i: ans) cout << i;
}