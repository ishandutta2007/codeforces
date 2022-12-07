#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long mod = 1e9 + 7;

int n, a[N];
pair < int, int > f[N];
pair < int, int > g[N];

void add(int &a, int b){
  a += b;
  if(a >= mod){
    a -= mod;
  }
}

void maximize(pair < int, int > &u, pair < int, int > &v){
  if(u.first < v.first){
    u = v;
  }
  else{
    if(u.first == v.first){
      add(u.second, v.second);
    }
  }
}

struct fenwick{
  pair < int, int > bit[N];
  void upd(int i, pair < int, int > key){
    for(; i < N; i += i & -i){
      maximize(bit[i], key);
    }
  }
  pair < int, int > ask(int i){
    pair < int, int > result = make_pair(0, 0);
    for(; i > 0; i &= i - 1){
      maximize(result, bit[i]);
    }
    return result;
  }
}up, dwn;

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  up.upd(1, make_pair(0, 1));
  for(int i = 1; i <= n; ++i){
    f[i] = up.ask(a[i]);
    ++f[i].first;
    up.upd(a[i] + 1, f[i]);
  }
  pair < int, int > answer;
  for(int i = 1; i <= n; ++i){
    maximize(answer, f[i]);
  }
  dwn.upd(1, make_pair(0, 1));
  for(int i = n; i >= 1; --i){
    g[i] = dwn.ask(N - a[i]);
    ++g[i].first;
    dwn.upd(N - a[i] + 1, g[i]);
  }
  for(int i = 1; i <= n; ++i){
    int len = f[i].first + g[i].first - 1;
    if(len != answer.first){
      putchar('1');
    }
    else{
      if((1LL * f[i].second * g[i].second) % mod != answer.second){
        putchar('2');
      }
      else{
        putchar('3');
      }
    }
  }
  return 0;
}