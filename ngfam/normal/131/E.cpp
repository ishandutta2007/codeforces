#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int m, n;
int b[N + N];
int c[N + N];
int x[N];
int y[N];
int cnt[N];
int ans[N];
pair < int, int > a[N];

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d%d", &m, &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; ++i){
    if(x[a[i].first] != 0){
      ++cnt[i];
      ++cnt[x[a[i].first]];
    }
    if(y[a[i].second] != 0){
      ++cnt[i];
      ++cnt[y[a[i].second]];
    }
    int u = (a[i].first + a[i].second);
    int v = (a[i].first - a[i].second) + N;
    if(b[u] != 0){
      ++cnt[i];
      ++cnt[b[u]];
    }
    if(c[v] != 0){
      ++cnt[i];
      ++cnt[c[v]];
    }
    b[u] = i;
    c[v] = i;
    x[a[i].first] = i;
    y[a[i].second] = i;
  }
  for(int i = 1; i <= n; ++i){
    ++ans[cnt[i]];
  }
  for(int i = 0; i <= 8; ++i){
    cout << ans[i] << " ";
  }
  return 0;
}