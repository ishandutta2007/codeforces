#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define offset 1000003

int n, val[100005], f, ans[100005];
stack<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> val[1];
  ans[1] = 0;
  q.push(1);
  FOR (i, 2, n) {
    cin >> val[i];
    while (!q.empty()) {
      int tmp = q.top();
      if (val[tmp] > val[i]) {
        ans[i] = max(ans[i], 1);
        break;
      } else {
        ans[i] = max(ans[i], 1 + ans[tmp]);
        q.pop();
      }
    }
    if (q.empty()) ans[i] = 0;
    q.push(i);
    f = max(ans[i], f);
    // cout << val[i] << ' ' << q.size() << endl;
  }
  cout << f;
}