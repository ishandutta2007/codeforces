#include <bits/stdc++.h>
using namespace std;

vector <int> child[200005];
int onetree(int x);
int alltree(int x);

int dpleaf[200005];

int leaf(int x) {
  int &ret = dpleaf[x];
  if (ret >= 0) {
    return ret;
  }
  if (child[x].size() == 0) {
    return 1;
  }
  ret = 0;
  for (int i = 0; i < (int)child[x].size(); i++) {
    ret += leaf(child[x][i]);
  }

  return ret;
}

int onetree(int x) {
  if (child[x].size() == 0) {
    return 0;
  }
  int maxi = 0;
  int total = leaf(x);
  for (int i = 0; i < (int) child[x].size(); i++) {
    maxi = max(maxi, total - leaf(child[x][i]) + alltree(child[x][i]));
  }
  return maxi;
}

int alltree(int x) {
  if (child[x].size() == 0) {
    return 0;
  }
  int total = 0;
  for (int i = 0; i < (int) child[x].size() ;i++) {
    total += onetree(child[x][i]);
  }
  return total;
}
int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;--b;
    child[a].push_back(b);
  }
  memset(dpleaf, -1, sizeof(dpleaf));
  int total = leaf(0);
  printf("%d %d\n", onetree(0) + 1, total - alltree(0));
}