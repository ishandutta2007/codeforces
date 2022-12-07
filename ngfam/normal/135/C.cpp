#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
char a[N];
int ok[2][2];

int check(int quest, int x, int y, int one, int zero){
  return max(0, y - one) <= quest && quest - max(0, y - one) >= max(0, x - zero);
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%s", a + 1);
  n = strlen(a + 1);
  int quest = 0, one = 0, zero = 0;
  for(int i = 1; i <= n; ++i){
    if(a[i] == '?'){
      ++quest;
    }
    if(a[i] == '1'){
      ++one;
    }
    if(a[i] == '0'){
      ++zero;
    }
  }
  if(one + quest >= zero + 2){
    ok[1][1] = 1;
  }
  if(zero + quest >= one + 1){
    ok[0][0] = 1;
  }
  int x = n / 2, y = (n + 1) / 2;
  if(check(quest, x, y, one, zero)){
    if(a[n] == '0' || (a[n] == '?' && check(quest - 1, x, y, one, zero + 1))){
      ok[1][0] = 1;
    }
    if(a[n] == '1' || (a[n] == '?' && check(quest - 1, x, y, one + 1, zero))){
      ok[0][1] = 1;
    }
  }
  for(int u = 0; u < 2; ++u){
    for(int v = 0; v < 2; ++v){
      if(ok[u][v] == 1) printf("%d%d\n", u, v);
    }
  }
  return 0;
}