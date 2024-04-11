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

int ask(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  int prod;
  cin >> prod;
  return prod;
}

const int lis[] = {4, 8, 15, 16, 23, 42};

int a[10];

int main() {
  set<int> s;
  REP(i, 6) s.emplace(lis[i]);
  int p = ask(1, 2);
  REP(i, 6) FOR(j, i + 1, 5) if (lis[i] * lis[j] == p) {
    a[1] = lis[i];
    a[2] = lis[j];
    s.erase(a[1]);
    s.erase(a[2]);
    break;
  }
  p = ask(1, 3);
  if (p % a[1] || !s.count(p / a[1])) swap(a[1], a[2]);
  a[3] = p / a[1];
  s.erase(a[3]);
  p = ask(4, 5);
  REP(i, 6) FOR(j, i + 1, 5) if (lis[i] * lis[j] == p && s.count(lis[i]) && s.count(lis[j])) {
    a[4] = lis[i];
    a[5] = lis[j];
    s.erase(a[4]);
    s.erase(a[5]);
    break;
  }
  p = ask(4, 6);
  if (p % a[4] || !s.count(p / a[4])) swap(a[4], a[5]);
  a[6] = p / a[4];
  cout << '!';
  FOR(i, 1, 6) cout << " " << a[i];
  cout << endl;
}