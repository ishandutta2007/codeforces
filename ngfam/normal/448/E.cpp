#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int rem = N;
vector < long long > divisor;
vector < int > adj[N];

void write(int x, int depth){
  if(rem == 0){
    return;
  }
  if(depth == 0 || x == 0){
    printf("%lld ", divisor[x]);
    --rem;
    return;
  }
  for(int i : adj[x]){
    if(rem == 0){
      return;
    }
    write(i, depth - 1);
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  long long n, k;
  scanf("%lld%lld", &n, &k);
  for(int i = 1; 1LL * i * i <= n; ++i){
    if(n % i == 0){
      divisor.push_back(i);
      if(1LL * i * i != n){
        divisor.push_back(n / i);
      }
    }
  }
  sort(divisor.begin(), divisor.end());
  for(int i = 0; i < divisor.size(); ++i){
    for(int j = 0; j <= i; ++j){
      if(divisor[i] % divisor[j] == 0){
        adj[i].push_back(j);
      }
    }
  }
  write(divisor.size() - 1, k);
  return 0;
}