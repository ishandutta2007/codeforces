#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long n, k, val, lis[10000007];

void f(long long x) {
  long long cnt0 = 1, cnt1 = 0;
  if (x <= 10000000) lis[x] += 1;
  while (x) {
    if (x & 1) {
      lis[x / 2] += cnt0;
      lis[x / 2 + 1] += cnt1;
      // long long tmp = cnt1;
      cnt1 = cnt0 + 2 * cnt1;
    } else {
      lis[x / 2] += cnt0 + cnt1;
      cnt0 = 2 * cnt0 + cnt1;
    }
    x /= 2;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  while (n--) {
    cin >> val;
    f(val);
  }
  long long cur = 0;
  FORD (i, 10000000, 1) {
    cur += lis[i];
    // if (lis[i]) cout << i << ' ' << lis[i] << endl;
    if (cur >= k) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}