#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define offset 1000003

int n, ans;
string s;

int main() {
  // ios::sync_with_stdio(false);
  cin >> n >> s;
  for (int i = n; i < s.size(); i += n) if (i >= 3) {
    int flag = 1;
    REP (j, 3) if (s[i - j - 1] != s[i - 1]) flag = 0;
    if (flag) s[i] = s[i - 1];
    ans += flag;
  }
  cout << ans;
}