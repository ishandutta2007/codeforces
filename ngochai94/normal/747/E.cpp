#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

string s;
vector<string> v, ans[1000006];
int maxLvl, id;

int string2int(string x) {
  int res = 0;
  for (char c: x) res = res * 10 + c - '0';
  return res;
}

void dfs(int x) {
  maxLvl = max(maxLvl, x);
  string text = v[id];
  int cnt = string2int(v[id + 1]);
  id += 2;
  ans[x].pb(text);
  REP (i, cnt) dfs(x + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  string cur = "";
  for (char c: s) {
    if (c == ',') v.pb(cur), cur = "";
    else cur += c;
  }
  v.pb(cur);
  while (id < v.size()) dfs(0);
  cout << maxLvl + 1 << endl;
  REP (i, maxLvl + 1) {
    for (string j: ans[i]) cout << j << ' ';
    cout << endl;
  }
}