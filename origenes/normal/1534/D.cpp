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

const int maxn = 2123;

int n;
int d[maxn];
bool used[maxn];
vector<int> G[maxn];

void ask(int u) {
  cout << "? " << u << endl;
  FOR(i, 1, n) cin >> d[i];
}

int main() {
  cin >> n;
  ask(1);
  int even = 0, odd = 0;
  FOR(i, 1, n) {
    if (d[i] % 2 == 0) even++;
    else odd++;
  }
  int root = 1;
  if (odd < even) {
    FOR(i, 1, n) if (d[i] % 2 == 1) {
      root = i;
      break;
    }
    ask(root);
  }
  queue<int> q;
  used[root] = true;
  FOR(i, 1, n) {
    if (d[i] == 1) {
      G[root].eb(i);
      used[i] = true;
    } else if (d[i] == 2) {
      q.emplace(i);
      used[i] = true;
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ask(u);
    FOR(i, 1, n) {
      if (d[i] == 1) {
        if (used[i]) G[i].eb(u);
        else G[u].eb(i);
        used[i] = true;
      }
      else if (d[i] == 2 && !used[i]) {
        q.emplace(i);
        used[i] = true;
      }
    }
  }
  cout << "!" << endl;
  FOR(i, 1, n) for (auto j : G[i]) cout << i << ' ' << j << endl;
}