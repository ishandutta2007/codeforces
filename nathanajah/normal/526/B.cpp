#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];

pair<int,int> dfs(int x) {
  if (2*x >= (1 << (n+1))) {
    return make_pair(0,0);
  }
  pair<int,int> curRes = make_pair(0,0);
  int maxi=-1, mini=1000000000;
  for (int k = 0; k < 2; k++) {
    int child = 2*x + k;
    pair<int,int> nxt = dfs(child);
    curRes.first += nxt.first;
    maxi = max(maxi, nxt.second + a[child]);
    mini = min(mini, nxt.second + a[child]);
  }
  curRes.first += (maxi - mini);
  curRes.second = maxi;
  return curRes;
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i < (1<<(n+1)); i++) {
    scanf("%d", &a[i]);
  }
  printf("%d\n", dfs(1).first);
}