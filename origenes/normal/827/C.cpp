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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

int n, fen[4][10][10][maxn], q;
char s[maxn];

inline int get(char s) {
  switch (s) {
    case 'A':
      return 0;
    case 'T':
      return 1;
    case 'G':
      return 2;
    case 'C':
      return 3;
    default:
      return -1;
  }
}

inline int lowbit(int x) {
  return x & -x;
}

void add(int *fen, int x, int d) {
  while (x <= n) {
    fen[x] += d;
    x += lowbit(x);
  }
}

int sum(const int *fen, int x) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  FOR(i, 1, n) {
    int ch = get(s[i]);
    FOR(b, 1, 10) {
      int rem = i % b;
      add(fen[ch][b - 1][rem], i, 1);
    }
  }
  scanf("%d", &q);
  while (q--) {
    int op, l, r;
    char e[15];
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%s", &l, e);
      int ch = get(s[l]);
      FOR(b, 1, 10) {
        int rem = l % b;
        add(fen[ch][b - 1][rem], l, -1);
      }
      ch = get(e[0]);
      FOR(b, 1, 10) {
        int rem = l % b;
        add(fen[ch][b - 1][rem], l, 1);
      }
      s[l] = e[0];
    } else {
      scanf("%d%d%s", &l, &r, e);
      int m = strlen(e), ans = 0;
      REP(i, m) {
        if (i + l > r) break;
        int ch = get(e[i]);
        ans += sum(fen[ch][m - 1][(i + l) % m], r);
        ans -= sum(fen[ch][m - 1][(i + l) % m], l - 1);
      }
      printf("%d\n", ans);
    }
  }
}