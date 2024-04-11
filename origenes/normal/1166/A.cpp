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

int n, ans;
string s;
int cnt[26];

int main() {
  cin >> n;
  while (n--) {
    cin >> s;
    cnt[s[0] - 'a']++;
  }
  REP(i, 26) {
    int x = cnt[i] + 1 >> 1, y = cnt[i] >> 1;
    ans += x * (x - 1) / 2 + y * (y - 1) / 2;
  }
  cout << ans;
}