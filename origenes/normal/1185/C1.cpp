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

const int maxn = 212345;

int n, M;
int t[maxn], tot[112], allowed[112], fail[112];
map<int, int> que[112];

int main() {
  scanf("%d%d", &n, &M);
  FOR(i, 1, n) scanf("%d", t + i);
  FOR(i, 1, 100) allowed[i] = M - i;
  FOR(i, 1, n) {
    FOR(j, 1, min(100, M)) {
      que[j][t[i - 1]]++;
      tot[j] += t[i - 1];
      while (tot[j] > allowed[j]) {
        que[j].rbegin()->_2--;
        fail[j]++;
        tot[j] -= que[j].rbegin()->_1;
        if (que[j].rbegin()->_2 == 0) que[j].erase(que[j].rbegin()->_1);
      }
    }
    printf("%d ", fail[t[i]]);
  }
}