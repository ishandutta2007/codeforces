#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

int n;
char s[maxn];
int a[maxn], cnt[maxn];

int main() {
  scanf("%s", s);
  int sz = strlen(s);
  int now = 0;
  ROF(i, sz - 1, 0) {
    now++;
    if (s[i] != '0') {
      cnt[n] = now;
      a[n] = s[i] - '0';
      n++;
      now = 0;
    }
  }
  int ans = 1;
  ll sum = cnt[n - 1], val = a[n - 1];
  ROF(i, n - 2, 0) {
    if (sum > cnt[i] || (sum == cnt[i] && val >= a[i])) ans++;
    else ans = 1;
    sum += cnt[i];
  }
  printf("%d", ans);
}