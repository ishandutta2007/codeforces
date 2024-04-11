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

int ask(string op, int i, int j) {
  cout << op << ' ' << i << ' ' << j << endl;
  int ret;
  cin >> ret;
  return ret;
}

const int maxn = (1 << 16) + 5;

int n;
int a[maxn], x[maxn], fi[maxn];

int main() {
  cin >> n;
  pii dup = {-1, -1};
  FOR(i, 2, n) {
    x[i] = ask("XOR", 1, i);
    if (!x[i]) dup = {1, i};
    else if (fi[x[i]]) dup = {fi[x[i]], i};
    else fi[x[i]] = i;
  }
  if (dup._1 != -1) {
    auto [i, j] = dup;
    a[i] = a[j] = ask("OR", i, j);
    if (i != 1) a[1] = x[i] ^ a[i];
  } else {
    int j = 0;
    FOR(i, 2, n) if (x[i] == 1) {
      j = i;
      break;
    }
    a[1] = ask("AND", 1, j);
    FOR(i, 2, n) if (i != j) {
      if (x[i] % 2 == 0) {
        int b = ask("AND", 1, i) % 2;
        if (b) a[1]++;
      } else {
        int b = ask("AND", i, j) % 2;
        if (!b) a[1]++;
      }
      break;
    }
  }
  FOR(i, 2, n) a[i] = a[1] ^ x[i];
  cout << '!';
  FOR(i, 1, n) cout << ' ' << a[i];
  cout << endl;
}