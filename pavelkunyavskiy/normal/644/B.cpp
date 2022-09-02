#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;

vector<ll> ans;
queue<pair<int, int>> q;
ll time;

void process_till(ll upto) {
  while (!q.empty() && time + q.front().second <= upto) {
    ans[q.front().first] = time + q.front().second;
    time += q.front().second;
    q.pop();
  }
}

int main() {
  int n, b;
  scanf("%d%d",&n, &b);
  ans.resize(n, -1);

  for (int i = 0; i < n; i++) {
    int d, t;
    scanf("%d%d",&t,&d);
    process_till(t);
    if (q.empty()) time = t;
    if ((int)q.size() <= b) q.push(make_pair(i, d));
  }

  process_till(1e18);

  for (int i = 0; i < n; i++)
    printf("%lld%c", ans[i], " \n"[i == n - 1]);
  return 0;
}