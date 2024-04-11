#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
const int mod = 998244353;

long long rev(long long a, long long b){
 return 1 < a ? b - rev(b % a, a) * b / a : 1;
}

int n;
int inv[N];
int fact[N];

long long comb(int x, int y) {
  return 1LL * fact[x] * (1LL * inv[y] * inv[x - y] % mod) % mod;
}

int main(){
  
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  cin >> n;
  fact[0] = inv[0] = 1;
  for(int i = 1; i < N; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % mod; 
  }
  
  inv[N - 1] = rev(fact[N - 1], mod);
  
  for(int i = N - 2; i >= 0; --i) {
    inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
  }
  
  long long ans = fact[n];

  long long sum = 0;
  
  for(int i = n - 1; i >= 0; --i) {
    long long cntx = comb(n, i) * fact[i] % mod;
    long long calc = (cntx * (n - i - 1)) % mod;
    
    
    ans += (1LL * i * calc) % mod; 
    ans %= mod;
  }
  
  cout << ans;
  
  return 0;
}