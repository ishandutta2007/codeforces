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

const int maxn = 312345;

int a[maxn], n;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  ll cnt[2] = {};
  FOR(i, 1, n) {
    int now = i & 1, other = 1 - now;
    cnt[now] += a[i] / 2;
    cnt[other] += a[i] / 2;
    cnt[now] += a[i] % 2;
  }
  printf("%lld", min(cnt[0], cnt[1]));
}