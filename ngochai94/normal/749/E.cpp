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

long long n, bitcnt[100005], bitsum[100005];

long long getsum(long long x) {
  long long res = 0;
  while (x > 0) {
    res += bitsum[x];
    x -= x & (-x);
  }
  return res;
}

void addsum(long long x, long long val) {
  while (x <= n) {
    bitsum[x] += val;
    x += x & (-x);
  }
}

long long getcnt(long long x) {
  long long res = 0;
  while (x > 0) {
    res += bitcnt[x];
    x -= x & (-x);
  }
  return res;
}

void addcnt(long long x, long long val) {
  while (x <= n) {
    bitcnt[x] += val;
    x += x & (-x);
  }
}

int main() {
  ios::sync_with_stdio(false);
  long double ans = 0;
  cin >> n;
  // n = 100000;
  long long S = n * (n + 1) / 2;
  FOR (i, 1, n) {
    long long val;
    cin >> val;
    // val = n - i + 1;
    // val = i;
    ans += (n - i + 1) * i * (i - 1);
    long long cnt = getcnt(n) - getcnt(val);
    long long summ = getsum(n) - getsum(val);
    // cout << cnt << ' ' << summ << endl;
    ans += cnt * S * 4 - (long double)(n - i + 1) * (long double)(summ) * 4;
    addcnt(val, 1);
    addsum(val, i);
    // BUG(ans);
  }
  // BUG(getsum(2));
  // BUG(ans / S);
  cout << setprecision(15) << ans / (4 * S);
}