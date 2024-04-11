#include <bits/stdc++.h>

using namespace std;

const int mod = (1e9) + 7;


const int N = 200020;

int n, q;

long long sum[N];
long long bit[N];

int a[N];
int w[N];

int main(){

  scanf("%d%d", &n, &q);
  
  
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
    
  for(int i = 1; i <= n; ++i){
    scanf("%d", w + i);
    
    
        
    for(int j = i; j < N; j += j & -j) {
      sum[j] += w[i];
      bit[j] += 1LL * (a[i] - i) * w[i];
      bit[j] %= mod;
    }
  }
  
  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);
    
    if(l < 0){
      l = -l;
      
      
      for(int i = l; i < N; i += i & -i) {
        bit[i] += 1LL * (a[l] - l) * (r - w[l]);
        bit[i] = ((bit[i] % mod) + mod) % mod;
        sum[i] += r - w[l];
      }
      
      w[l] = r;
    }
    else{
      int lo = l, hi = r, pos = hi;
      
      long long all = 0;
      for(int i = r; i > 0; i &= i - 1) all += sum[i];
      for(int i = l - 1; i > 0; i &= i - 1) all += sum[i];
      
      
      while(lo <= hi){
        int m = (lo + hi) >> 1;
        
        long long tot = 0;
        for(int i = m; i > 0; i &= i - 1) tot += sum[i];
        
        if(tot * 2 >= all) {
          pos = m;
          hi = m - 1;
        }
        else lo = m + 1;
      }
      
      
      int best = a[pos] - pos;
      
      
      
      long long lef = 0, rig = 0;
      long long ans = 0;
      for(int i = pos - 1; i > 0; i &= i - 1) {
        lef = (lef + sum[i]) % mod;
        rig = (rig - sum[i] + 1LL * mod * mod) % mod;
        ans = (ans - bit[i] * 2 + mod + mod) % mod;
      }
      for(int i = l - 1; i > 0; i &= i - 1) ans = (ans + bit[i]) % mod, lef = (lef - sum[i] + 1LL * mod * mod) % mod;
      for(int i = r; i > 0; i &= i - 1) ans = (ans + bit[i]) % mod, rig = (rig + sum[i]) % mod;
      
      printf("%d\n", (ans + lef * best - rig * best + 1LL * mod * mod) % mod); 
    }
  }

	return 0;
}