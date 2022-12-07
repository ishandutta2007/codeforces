#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
  #endif // ONLINE_JUDGE
  scanf("%d", &n);
  if(n % 2 == 1){
    puts("black");
  }
  else{
    puts("white");
    puts("1 2");
  }
  return 0;
}