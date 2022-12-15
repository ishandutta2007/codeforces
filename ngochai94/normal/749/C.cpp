#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, d, r, remd, remr;
string s;
queue<char> q;
char ans;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  for (char c: s) q.push(c);
  for (char c: s) if (c == 'R') remr++; else remd++;
  while (!q.empty()) {
    if (!remd) {
      cout << 'R';
      return 0;
    }
    if (!remr) {
      cout << "D";
      return 0;
    }
    char cur = q.front();
    // BUG(cur);
    ans = cur;
    q.pop();
    if (cur == 'D') {
      if (r) r--, remd--;
      else {
        d++;
        q.push(cur);
      }
    } else {
      if (d) d--, remr--;
      else {
        r++;
        q.push(cur);
      }
    }
  }
  cout << ans;
}