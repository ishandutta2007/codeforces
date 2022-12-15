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

long long two[222];
string s;

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  int n = s.size();
  two[0] = 1;
  FOR (i, 1, 200) two[i] = (two[i - 1] * 2) % mod;
  long long ans = 0;
  REP (i, n) if (s[i] == '1') {
    ans += two[2 * n - i - 2];
    ans %= mod;
  }
  cout << ans;
}