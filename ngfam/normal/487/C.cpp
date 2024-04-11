#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int prime(int x){
  for(int i = 2; i * i <= x; ++i){
    if(x % i == 0){
      return 0;
    }
  }
  return 1;
}

int powmod(int x, int y){
  if(y == 0){
    return 1;
  }
  if(y == 1){
    return x;
  }
  int calc = powmod(x, y >> 1);
  calc = (1LL * calc * calc) % n;
  if(y & 1){
    calc = (1LL * calc * x) % n;
  }
  return calc;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d", &n);
  if(n > 4 && prime(n) == 0){
    puts("NO");
    return 0;
  }
  puts("YES");
  if(n == 4){
    puts("1\n3\n2\n4");
    return 0;
  }
  a[1] = 1;
  a[2] = 2;
  for(int i = 3; i < n; ++i){
    a[i] = (1LL * i * powmod(i - 1, n - 2)) % n;
  }
  a[n] = n;
  for(int i = 1; i <= n; ++i){
    printf("%d\n", a[i]);
  }
  return 0;
}