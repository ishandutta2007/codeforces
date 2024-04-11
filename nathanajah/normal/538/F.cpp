#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200005];
vector <int> upd[200005];
int parent[200005];

int main() {
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    parent[i] = i-1;
    if (parent[i] > 0) {
      upd[(i-1)/parent[i] + 1].push_back(i);
    }
    if (arr[i] < arr[parent[i]]) ans++;
  }
  printf("%d",ans);
  for (int i = 2; i < n; i++) {
    for (int j = 0; j < (int)upd[i].size(); j++) {
      int now = upd[i][j];
      if (arr[now] < arr[parent[now]]) ans--;
      parent[now] = (now-1)/i;
      if (parent[now] > 0) {
        upd[(now-1)/parent[now] + 1].push_back(now);
      }
      if (arr[now] < arr[parent[now]]) ans++;
    }
    upd[i].clear();
    vector <int>(upd[i]).swap(upd[i]);
    printf(" %d",ans);
  }
  printf("\n");
}