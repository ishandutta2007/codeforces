#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct fenwick{
  int bit[N];
  void upd(int i, int val){
    for(; i < N; i += i & -i){
      bit[i] = max(bit[i], val);
    }
  }
  int ask(int i){
    int result = 0;
    for(; i > 0; i &= i - 1){
      result = max(result, bit[i]);
    }
    return result;
  }
}fwt;

int n;
int a[N];
int ans[N];
vector < int > small;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    small.push_back(a[i]);
  }
  sort(small.begin(), small.end());
  small.resize(unique(small.begin(), small.end()) - small.begin());
  for(int i = 1; i <= n; ++i){
    a[i] = (lower_bound(small.begin(), small.end(), a[i]) - small.begin()) + 1;
  }
  for(int i = n; i >= 1; --i){
    int best = fwt.ask(a[i] - 1);
    if(best == 0){
      ans[i] = -1;
    }
    else{
      ans[i] = best - i - 1;
    }
    fwt.upd(a[i], i);
  }
  for(int i = 1; i <= n; ++i){
    printf("%d ", ans[i]);
  }
  return 0;
}