#include <bits/stdc++.h>

#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = (1 << 17);

typedef pair<int, int> pi;

int n;
int sum[N], sl[N];
queue <int> a;
vector <pair<int, int> > res;

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> sl[i] >> sum[i];
    if (sl[i] == 1) a.push(i);
  }
  while(!a.empty()) {
    int u = a.front();
    a.pop();
    if (sl[u] != 1) continue;
    res.push_back(make_pair(u, sum[u]));
    sl[sum[u]]--;
    sum[sum[u]] ^= u;
    if (sl[sum[u]] == 1) a.push(sum[u]);
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) cout << res[i].first << " " << res[i].second << endl;
  return 0;
}