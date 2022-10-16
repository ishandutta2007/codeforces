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

const int maxn = 5123;

string s[maxn];
int k, n, cnt[maxn];
bool rep = true;

bool check(int i1, int i2) {
  FOR(i, 2, k) {
    int now = cnt[i];
    if (s[1][i1] != s[i][i1]) now--;
    if (s[1][i2] != s[i][i2]) now--;
    if (s[1][i1] != s[i][i2]) now++;
    if (s[1][i2] != s[i][i1]) now++;
    if (now != 2 && (now || !rep)) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> k >> n;
  set<string> st;
  FOR(i, 1, k) {
    cin >> s[i];
    string tmp = s[i];
    sort(all(tmp));
    st.insert(tmp);
  }
  if (st.size() > 1) {
    cout << -1;
    return 0;
  }
  if (k == 1) {
    swap(s[1][0], s[1][1]);
    cout << s[1];
    return 0;
  }
  set<char> ch;
  for (auto it : s[1]) ch.insert(it);
  if (ch.size() == n) rep = false;
  FOR(i, 2, k) REP(j, n) if (s[1][j] != s[i][j]) cnt[i]++;
  REP(i, n) FOR(j, i + 1, n - 1) if (check(i, j)) {
        swap(s[1][i], s[1][j]);
        cout << s[1];
        return 0;
      }
  cout << -1;
}