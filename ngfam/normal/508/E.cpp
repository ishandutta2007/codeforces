#include <bits/stdc++.h>
#define prev riven

using namespace std;

const int N = 666;

int n;
char s[N];
int f[N][N];
int prev[N][N];
pair < int, int > a[N];

int solve(int l, int r){
  int len = (r - l + 1) * 2 - 1;
  for(int i = l; i <= r; ++i){
    if(a[i].first > len || a[i].second < len){
      return 0;
    }
    len -= 2;
    if(f[i + 1][r] == 1){
      prev[l][r] = -(i - l + 1);
      return 1;
    }
  }
  return 1;
}

bool maximize(int &u, int v){
  if(u < v){
    u = v;
    return true;
  }
  return false;
}

void backtrack(int l, int r){
  //cerr << l << " " << r << endl;
  if(prev[l][r] == 0){
    for(int i = l; i <= r; ++i){
      putchar('(');
    }
    for(int i = l; i <= r; ++i){
      putchar(')');
    }
    return;
  }
  if(prev[l][r] < 0){
    for(int x = 1; x <= abs(prev[l][r]); ++x){
      putchar('(');
    }
    backtrack(l + abs(prev[l][r]), r);
    for(int x = 1; x <= abs(prev[l][r]); ++x){
      putchar(')');
    }
    return;
  }
  backtrack(l, prev[l][r]);
  backtrack(prev[l][r] + 1, r);
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  for(int i = 1; i <= n; ++i){
    for(int j = i; j >= 1; --j){
      if(solve(j, i) == 1){
        f[j][i] = 1;
        continue;
      }

      for(int k = j; k < i; ++k){
        if(maximize(f[j][i], f[j][k] & f[k + 1][i])){
          prev[j][i] = k;
          break;
        }
      }
    }
  }
  if(f[1][n] == 0){
    puts("IMPOSSIBLE");
  }
  else{
    backtrack(1, n);
  }
  return 0;
}