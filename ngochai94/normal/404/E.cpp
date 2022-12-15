#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001deployed
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define offset 1000003

int high, low, chs, n, cnt, vst[2000006];
string s;
char l, r;

bool ok(int x) {
  // BUG(x);
  cnt++;
  int cur = 0;
  for (char c: s) {
    // BUG(cur);
    vst[cur + offset] = cnt;
    if (c == l) cur--;
    else cur++;
    if (cur == x) cur++;
  }
  // BUG(cur);
  // cout << vst[cur] << ' ' << cnt << endl;
  return vst[cur + offset] != cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  l = 'L';
  r = 'R';
  n = s.size();
  if (s[n - 1] == 'L') swap(l, r);
  if (ok(-n-10)) {
    cout << 1;
    return 0;
  }
  // BUG(ok(-1));
  high = n;
  low = 1;
  while (low < high) {
    chs = (low + high) / 2;
    if (ok(-chs)) low = chs + 1;
    else high = chs;
  }
  cout << low - 1;
}