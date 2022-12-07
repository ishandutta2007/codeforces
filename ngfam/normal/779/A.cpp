#include <bits/stdc++.h>

using namespace std;

int n;
int a[111];
int b[111];
int cnt[111];
int cnta[111];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "W", stdout);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
    ++cnt[a[i]];
    ++cnta[a[i]];
  }
  for(int i = 1; i <= n; ++i){
    scanf("%d", b + i);
    ++cnt[b[i]];
  }
  for(int i = 1; i <= 5; ++i){
    if(cnt[i] % 2 != 0){
      cout << -1;
      return 0;
    }
  }
  int answer = 0;
  for(int i = 1; i <= 5; ++i){
    if(cnta[i] < cnt[i] / 2){
      answer += cnt[i] / 2 - cnta[i];
    }
  }
  cout << answer;
  return 0;
}