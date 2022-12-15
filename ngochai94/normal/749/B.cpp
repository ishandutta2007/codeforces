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

int x[3], y[3];
set<pair<int, int> > s;

int main() {
  ios::sync_with_stdio(false);
  REP (i, 3) cin >> x[i] >> y[i];
  s.insert({x[0] + x[1] - x[2], y[0] + y[1] - y[2]});
  s.insert({x[0] + x[2] - x[1], y[0] + y[2] - y[1]});
  s.insert({x[2] + x[1] - x[0], y[2] + y[1] - y[0]});
  cout << s.size() << endl;
  for (auto p: s) cout << p._1 << ' ' << p._2 << endl;
}