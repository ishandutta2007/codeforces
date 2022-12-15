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

int n, p, k, a, b;
pair<int, pair<int, int> > ord[100005], ord2[100005];

int main() {
  // ios::sync_with_stdio(false);
  cin >> n >> p >> k;
  REP (i, n) {
    cin >> a >> b;
    ord[i] = {b, {-a, i}};
  }
  sort(ord, ord + n);
  int minid = n;
  FOR (i, p - k, n - 1) {
    a = -ord[i]._2._1;
    b = ord[i]._1;
    ord2[i] = {-a, {-i, b}};
  }
  sort(ord2 + p - k, ord2 + n);
  FOR (i, p - k, p - 1) {
    int id = -ord2[i]._2._1;
    minid = min(minid, id);
    cout << ord[id]._2._2 + 1 << ' ';
  }
  REP (i, p - k) {
    minid--;
    cout << ord[minid]._2._2 + 1 << ' ';
  }
}