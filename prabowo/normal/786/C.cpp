#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];
int ans[N];

int vis[N];
int f(int k) {
  int ret = 0;
  int cnt = 0;
  for (int i=1; i<=n; i++) vis[i] = -1;
  
  for (int i=0; i<n; i++) {
    cnt += (vis[a[i]] < ret);
    vis[a[i]] = ret;
    
    if (cnt > k) {
      cnt = 1;
      vis[a[i]] = ++ret;
    } 
  }
  
  return ret + 1;
}

void solve(int l, int r) {
  // cerr << l << " " << r << endl;
  if (l + 1 >= r) return;
  if (ans[l] == ans[r]) {
    for (int i=l+1; i<r; i++) ans[i] = ans[l];
    return;
  }
  
  int mid = l + r >> 1;  
  ans[mid] = f(mid);
  solve(l, mid);
  solve(mid, r);
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", a + i);
  
  ans[1] = f(1), ans[n] = 1;
  solve(1, n);
  for (int i=1; i<=n; i++) printf("%d ", ans[i]); printf("\n");
  return 0;
}