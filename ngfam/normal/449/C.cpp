#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, sz;
int dead[N];
pair < int, int > answer[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 3; i <= n; ++i){
    vector < int > lst;
    for(int j = i; j <= n; j += i){
      if(dead[j] != 0){
        continue;
      }
      lst.push_back(j);
    }
    if(lst.size() % 2 == 1 && lst.size() > 1){
      for(int x = 1; x < lst.size(); ++x){
        if(lst[x] == 2 * i){
          lst.erase(lst.begin() + x);
          break;
        }
      }
    }
    for(int x = 0; x < int(lst.size()) - 1; x += 2){
      answer[++sz] = make_pair(lst[x], lst[x + 1]);
      dead[lst[x]] = 1;
      dead[lst[x + 1]] = 1;
    }
  }
  int current = 0;
  for(int i = 1; i <= n; ++i){
    if(dead[i] == 0 && i % 2 == 0){
      if(current != 0){
        answer[++sz] = make_pair(i, current);
        current = 0;
      }
      else{
        current = i;
      }
    }
  }
  printf("%d\n", sz);
  #ifndef pts
    for(int i = 1; i <= sz; ++i){
      printf("%d %d\n", answer[i].first, answer[i].second);
    }
  #endif // pts
  return 0;
}