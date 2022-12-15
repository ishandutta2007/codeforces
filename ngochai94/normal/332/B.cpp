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

long long n, k, lis[200005], pre[200005], dp[200005], dp2[200005], val[200005], val2[200005];

int main() {
  // ios::sync_with_stdio(false);
  cin >> n >> k;
  FOR (i, 1, n) cin >> lis[i];
  FOR (i, 1, n) {
    pre[i] = pre[i - 1] + lis[i];
  }
  dp[n - k + 1] = n - k + 1;
  val[n - k + 1] = pre[n] - pre[n - k];
  FORD (i, n - k, 1) {
    int id = dp[i + 1];
    if (pre[i + k - 1] - pre[i - 1] >= pre[id + k - 1] - pre[id - 1]) dp[i] = i;
    else dp[i] = id;
    val[i] = max(val[i + 1], pre[i + k - 1] - pre[i - 1]);
  }
  dp2[n - k - k + 1] = n - k - k + 1;
  val2[n - k - k + 1] = pre[n] - pre[n - k - k];
  FORD (i, n - k - k, 1) {
    int id = dp2[i + 1];
    if (pre[i + k - 1] - pre[i - 1] + val[i + k] >= pre[id + k - 1] - pre[id - 1] + val[id + k]) dp2[i] = i;
    else dp2[i] = id;
  }
  long long a = dp2[1];
  long long b = dp[a + k];
  cout << a << ' ' << b;
}