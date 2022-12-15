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

int ans, n;
string s;

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  n = s.size();
  char lst = ' ';
  int cnt = 0;
  for (char c: s) {
    if (c == lst) cnt++;
    else {
      if (cnt && cnt % 2 == 0) ans++;
      lst = c;
      cnt = 1;
    }
  }
  if (cnt % 2 == 0) ans++;
  cout << ans;
}