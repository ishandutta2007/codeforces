#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ans = 0;
ll f(ll k){
  return (k*(k-1))/2;
}

ll cnt[40];

int main(){
  int n;
  scanf("%i",&n);
  int k;
  for(int i = 0;i<n;i++){
    scanf("%i",&k);
    cnt[__builtin_popcount(k)]++;
  }
  for(int j = 0;j<40;j++)
    ans += f(cnt[j]);
  printf("%I64d\n",ans);
  return 0;
}