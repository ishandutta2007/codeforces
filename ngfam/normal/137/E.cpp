#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 10, M = 4e5 + 1;

struct fenwick{
  int bit[N];
  void init(){
    memset(bit, 60, sizeof bit);
  }
  void upd(int i, int val){
    for(; i < N; i += i & -i){
      bit[i] = min(bit[i], val);
    }
  }
  int ask(int i){
    int result = 1e9;
    for(; i > 0; i &= i - 1){
      result = min(result, bit[i]);
    }
    return result;
  }
}fwt;

int n;
int a[N];
char r[N];
int sum[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%s", r + 1);
  n = strlen(r + 1);
  for(int i = 1; i <= n; ++i){
    char x = tolower(r[i]);
    if(x == 'e' || x == 'a' || x == 'i' || x == 'o' || x == 'u'){
      a[i] = -1;
    }
    else{
      a[i] = 2;
    }
  }
  partial_sum(a + 1, a + n + 1, sum + 1);
  fwt.init();
  fwt.upd(M, 0);
  int len = 0;
  for(int i = 1; i <= n; ++i){
    len = max(len, i - fwt.ask(sum[i] + M));
    fwt.upd(sum[i] + M, i);
  }
  if(len == 0){
    cout << "No solution";
    return 0;
  }
  cout << len << " ";
  int answer = 0;
  for(int i = len; i <= n; ++i){
    if(sum[i] - sum[i - len] >= 0){
      ++answer;
    }
  }
  cout << answer;
  return 0;
}