#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, q;
char a[N];
char best[N];
char read[N];
map < char, bool > good;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%s", best + 1);
  scanf("%s", a + 1);
  m = strlen(best + 1);
  n = strlen(a + 1);
  for(int i = 1; i <= m; ++i){
    good[best[i]] = 1;
  }
  scanf("%d", &q);
  bool sao = false;
  for(int i = 1; i <= n; ++i){
    if(a[i] == '*'){
      sao = true;
    }
  }
  while(q--){
    scanf("%s", read + 1);
    int x = strlen(read + 1);
    if(sao == false && n != x){
      puts("NO");
      continue;
    }
    if(x < n - 1){
      puts("NO");
      continue;
    }
    int pter = 1, ok = 0;
    for(int i = 1; i <= n; ++i){
      if(a[i] == read[pter]){
        ++pter;
        continue;
      }
      else{
        if(a[i] != '?' && a[i] != '*'){
          puts("NO");
          ok = 1;
          break;
        }
        if(a[i] == '?'){
          if(!good[read[pter]]){
            puts("NO");
            ok = 1;
            break;
          }
          ++pter;
          continue;
        }
        int rem = x - (n - 1), fail = 0;
        for(int f = 1; f <= rem; ++f){
          if(good[read[pter]]){
            fail = 1;
            break;
          }
          ++pter;
        }
        if(fail == 1){
          puts("NO");
          ok = 1;
          break;
        }
      }
    }
    if(!ok){
      puts("YES");
    }
  }
  return 0;
}