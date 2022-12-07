#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k;
int a[N];
set < int > x;
map < int, int > cnt;

void ins(int u, int add){
  cnt[u] += add;
  if(cnt[u] == 1){
    x.insert(u);
  }
  else{
    x.erase(u);
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  for(int i = 1; i <= k; ++i){
    ins(a[i], 1);
  }
  if(x.size() == 0){
    puts("Nothing");
  }
  else{
    printf("%d\n", *(--x.end()));
  }
  for(int i = k + 1; i <= n; ++i){
    ins(a[i], 1);
    ins(a[i - k], -1);
    if(x.size() > 0){
      printf("%d\n", *(--x.end()));
    }
    else{
      puts("Nothing");
    }
  }
  return 0;
}