#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, k;
pair < int, int > a[N];

bool cmp(pair < int, int > u, pair < int, int > v){
  return u.second - u.first > v.second - v.first;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "W", stdout);
  #endif // pts
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i].first);
  }
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i].second);
  }
  sort(a + 1, a + n + 1, cmp);
  int answer = 0;
  for(int i = 1; i <= k; ++i){
    answer += a[i].first;
  }
  int j = k + 1;
  for(; j <= n; ++j){
    if(a[j].second - a[j].first < 0){
      break;
    }
    else{
      answer += a[j].first;
    }
  }
  for(; j <= n; ++j){
    answer += a[j].second;
  }
  cout << answer;
  return 0;
}