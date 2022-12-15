#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001deployed
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define offset 1000003

int n;
vector<int> v[26];
string s;

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  n = s.size();
  REP (i, n) v[s[i] - 'A'].pb(i);
  int ans = 0;
  REP (i, 26) if (v[i].size()) {
    // BUG(i);
    int cnt = 0;
    int lst = -1;
    for (int j: v[i]) {
      // BUG(j);
      if (lst == -1) {
        lst = j;
        cnt = 1;
        continue;
      }
      if ((j - lst) & 1) {
        cnt++;
        lst = j;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans;
}