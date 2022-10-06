#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int k;
int n;
int vs[314514];
bool used[314514];
bool considered[314514];
priority_queue<int> q;

bool check(int x) {
  fill(used, used+n+1, false);
  fill(considered, considered+n+1, false);
  q.push(0);
  used[0] = true;
  while (!q.empty()) {
    int v = q.top(); q.pop();
    if (considered[v]) continue;
    considered[v] = true;
    
    int u = v+k;
    if (u > n) continue;

    while (u <= n && vs[u-1]-vs[v] <= x) {
      if (!used[u]) {
        q.push(u);
        used[u] = true;
      } else break;
      ++u;
    }
  }

  return used[n];
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &vs[i]);
  }
  sort(vs, vs+n);
  
  int low = -1;
  int high = INF+1;
  while (high-low > 1) {
    int mid = (high+low)/2;
    if (check(mid)) high = mid;
    else low = mid;
  }

  printf("%d\n", high);
}