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

const int maxn = 1123456;
const int MOD = 998244353;

char s[maxn * 2], a[maxn], lo[maxn], hi[maxn];
int z[maxn * 2], dp[maxn];
vector<int> in[maxn], out[maxn];

inline void upd(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

void get_z(int n) {
  int l = 0, r = 0;
  z[0] = 0;
  FOR(i, 1, n - 1) {
    if (r >= i) {
      assert(l != 0);
      if (z[i - l] + i <= r) z[i] = z[i - l];
      else {
        int nxt = r - i;
        while (r < n && s[r] == s[nxt]) r++, nxt++;
        r--;
        z[i] = nxt;
        l = i;
      }
    } else {
      r = i;
      int nxt = 0;
      while (r < n && s[r] == s[nxt]) r++, nxt++;
      l = i;
      r--;
      z[i] = nxt;
    }
  }
//  REP(i, n) printf("%d ", z[i]);
}

int main() {
  scanf("%s%s%s", a + 1, lo + 1, hi + 1);
  int n = strlen(a + 1), len_l = strlen(lo + 1), len_r = strlen(hi + 1);
  strcpy(s, lo + 1);
  s[len_l] = '$';
  strcpy(s + len_l + 1, a + 1);
  get_z(len_l + n + 1);
  FOR(i, 1, n - len_l + 1) if (a[i] != '0') {
    int idx = len_l + i;
    if (z[idx] == len_l || a[z[idx] + i] > lo[z[idx] + 1]) in[i + len_l - 1].eb(i);
    else in[i + len_l].eb(i);
  }
  strcpy(s, hi + 1);
  s[len_r] = '$';
  strcpy(s + len_r + 1, a + 1);
  get_z(len_r + n + 1);
  if (lo[1] != '0') {
    FOR(i, 1, n - len_r + 1) if (a[i] != '0') {
      int idx = len_r + i;
      if (z[idx] == len_r || a[z[idx] + i] < hi[z[idx] + 1]) out[i + len_r].eb(i);
      else out[i + len_r - 1].eb(i);
    }
  } else {
    FOR(i, 1, n - len_r + 1) if (a[i] != '0') {
        int idx = len_r + i;
        if (z[idx] == len_r || a[z[idx] + i] < hi[z[idx] + 1]) out[i + len_r].eb(i);
        else out[i + len_r - 1].eb(i);
    }
    FOR(i, 1, n) if (a[i] == '0') {
      in[i].eb(i);
      out[i + 1].eb(i);
    }
  }
  dp[0] = 1;
  int way = 0;
  FOR(i, 1, n) {
    for (auto it : in[i]) upd(way, dp[it - 1]);
    for (auto it : out[i]) upd(way, MOD - dp[it - 1]);
    dp[i] = way;
  }
  printf("%d", dp[n]);
}