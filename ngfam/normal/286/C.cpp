#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n, m;
int a[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  scanf("%d", &m);
  for(int i = 1; i <= m; ++i){
    int x;
    scanf("%d", &x);
    a[x] *= -1;
  }
  stack < int > lst;
  for(int i = n; i >= 1; --i){
    if(lst.empty()){
      lst.push(i);
      continue;
    }
    if(a[i] > 0){
      if(abs(a[lst.top()]) == a[i]){
        a[lst.top()] = -abs(a[lst.top()]);
        lst.pop();
        continue;
      }
    }
    lst.push(i);
  }
  if(!lst.empty()){
    puts("NO");
  }
  else{
    puts("YES");
    for(int i = 1; i <= n; ++i){
      printf("%d ", a[i]);
    }
  }
  return 0;
}