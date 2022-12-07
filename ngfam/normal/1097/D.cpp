#include <bits/stdc++.h>

using namespace std;

const int N = 10110;
const int mod = 1e9 + 7;

long long rev(long long a, long long b){
 return 1 < a ? b - rev(b % a, a) * b / a : 1;
}

long long f[20][100];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  long long n; int k;
  cin >> n >> k;

  long long x = n;
  vector < long long > divisors;
  vector < pair < long long, int > > factors;

  for(long long i = 1; i * i <= n; ++i){
    if(n % i == 0) {
      divisors.push_back(i);
      if(n / i != i) divisors.push_back(n / i);
    } 

    if(i > 1 && x % i == 0) {
      factors.emplace_back(i, 0);
      while(x % i == 0) {
        ++factors.back().second;
        x /= i;
      }
    }
  }

  if(x > 1) factors.emplace_back(x, 1);

  for(int i = 0; i < factors.size(); ++i) {
    f[i][factors[i].second] = 1;
    for(int times = 1; times <= k; ++times) {
      long long tot = 0;
      for(int j = factors[i].second; j >= 0; --j) {
        tot += f[i][j] * rev(j + 1, mod) % mod;
        tot %= mod; 
        f[i][j] = tot;
      }
    }
  }

  long long ans = 0;

  for(long long x : divisors) {
    long long way = 1, old = x;
    for(int i = 0; i < factors.size(); ++i) {
      int cnt = 0;
      while(x % factors[i].first == 0) ++cnt, x /= factors[i].first;
      way = (way * f[i][cnt]);
      way %= mod;
    }
    ans = (ans + way * (old % mod)) % mod;
  }

  cout << ans << endl;
  
	return 0;
}