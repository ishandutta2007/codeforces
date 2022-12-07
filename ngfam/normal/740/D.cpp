#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

int n, sz;
int arr[N];
int brr[N];
int foo[N];
int out[N];
vector < int > adj[N];

struct fenwick{
  long long bit[N];
  void upd(int i, int val){
    for(; i < N; i += i & -i){
      bit[i] += val;
    }
  }
  long long ask(int i){
    long long result = 0;
    for(; i > 0; i &= i - 1){
      result += bit[i];
    }
    return result;
  }
}fwt, fwt2;

void dfs(int u){
  if(u != 1){
    fwt.upd(1, brr[u]);
    fwt.upd(sz + 1, -brr[u]);
    int low = 1, high = sz, ans = sz + 1;
    while(low <= high){
      int val = (low + high) >> 1;
      if(fwt.ask(val) > arr[u]){
        low = val + 1;
      }
      else{
        ans = val;
        high = val - 1;
      }
    }
    fwt2.upd(ans, 1);
    fwt2.upd(sz + 1, -1);
  }
  foo[++sz] = u;
  for(int v : adj[u]){
    dfs(v);
  }
  out[u] = fwt2.ask(sz);
  fwt2.upd(sz, -out[u]);
  fwt2.upd(sz + 1, out[u]);
  fwt.upd(1, -brr[u]);
  fwt.upd(sz, brr[u]);
  --sz;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen(".out", "w", stdout);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", arr + i);
  }
  for(int i = 1; i < n; ++i){
    int value;
    scanf("%d%d", &value, brr + i + 1);
    adj[value].push_back(i + 1);
  }
  dfs(1);
  for(int i = 1; i <= n; ++i){
    printf("%d ", out[i]);
  }
  return 0;
}