#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
const long long mod = 1e9 + 7;

int n;
char a[N];
int prefix[N];
long long pw[N];
long long hashes[N];

long long ask(int l, int r){
  return (hashes[r] - hashes[l - 1] * pw[r - l + 1] + mod * mod) % mod;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif
  scanf("%s", a + 1);
  n = strlen(a + 1);
  pw[0] = 1;
  for(int i = 1; i <= n; ++i){
    hashes[i] = (hashes[i - 1] * 31 + a[i] - 'a') % mod;
    pw[i] = (pw[i - 1] * 31) % mod;
  }
  for(int i = 1; i <= n; ++i){
    prefix[i] = prefix[i - 1];
    if(ask(1, i) == ask(n - i + 1, n)){
      prefix[i] = i;
    }
  }
  int answer = 0;
  for(int i = 2; i <= n; ++i){
    int low = 0, high = n - i, result = 0;
    while(low <= high){
      int val = (low + high) >> 1;
      if(ask(i, i + val - 1) == ask(1, 1 + val - 1)){
        result = val;
        low = val + 1;
      }
      else{
        high = val - 1;
      }
    }
    if(answer < prefix[result]){
      answer = prefix[result];
    }
  }
  if(answer == 0){
    puts("Just a legend");
  }
  else{
    for(int i = 1; i <= answer; ++i){
      putchar(a[i]);
    }
  }
  return 0;
}