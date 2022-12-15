#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, val, id, ans[300005];
pair<int, int> p[300005];
queue<int> q;

int main(){
  cin >> n;
  REP (i, n) {
    cin >> val;
    p[i] = {val, i};
  }
  sort(p, p + n);
  int cur = -1;
  int cnt = 0;
  REP (i, n) {
    id = p[i]._2;
    val = p[i]._1;
    if (val == cur) {
      q.push(id);
    } else {
      FOR (j, cur + 1, val - 1) {
        if (q.empty()) break;
        ans[q.front()] = j;
        q.pop();
      }
      ans[id] = val;
      cur = val;
      cnt = 1;
    }
  }
  while (!q.empty()) {
    ans[q.front()] = ++cur;
    q.pop();
  }
  REP (i, n) cout << ans[i] << ' ';
}