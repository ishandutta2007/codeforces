#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int p[N];

bool vis[N];

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", p + i);
    --p[i];
  }
  
  vector<int> comp;
  for (int i=0; i<n; i++) {
    if (vis[i]) continue;
    
    int cnt = 0;
    int cur = i;
    while (vis[cur] == 0) {
      vis[cur] = 1;
      cnt++;
      cur = p[cur];
    }
    
    comp.push_back(cnt);
  }
  
  sort(comp.begin(), comp.end(), greater<int>());
  long long sum = 0;
  if (comp.size() == 1) sum += 1LL * comp[0] * comp[0];
  else sum += 1LL * (comp[0] + comp[1]) * (comp[0] + comp[1]);
  for (int i=2; i<comp.size(); i++) sum += 1LL * comp[i] * comp[i];
  
  printf("%lld\n", sum);
  
  return 0;
}