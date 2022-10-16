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

long long n, k, val, cur, ans;

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  while (n--) {
    cin >> val;
    ans += (val + cur) / k;
    long long ncur = (val + cur) % k;
    if (ncur <= val) {
      cur = ncur;
    } else {
      cur = 0;
      ans++;
    }
  }
  cout << ans + (cur + k - 1) / k;
}