#include <bits/stdc++.h>

using namespace std;

const int N = 2000100;

int n, maxval;
int a[N];
int slv[N];
int done[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    maxval = max(maxval, a[i]);
    slv[a[i] + 1] = a[i];
  }
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= maxval * 2; ++i){
    slv[i] = max(slv[i], slv[i - 1]);
  }
  int answer = 0;
  for(int i = 1; i <= n; ++i){
    if(done[a[i]]){
      continue;
    }
    done[a[i]] = 1;
    for(int j = a[i] + a[i]; j <= maxval * 2; j += a[i]){
      answer = max(answer, slv[j] % a[i]);
    }
  }
  cout << answer;
  return 0;
}