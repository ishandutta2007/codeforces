#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int n, m, x, y, z, sz;
pair < int, int > arr[N];

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &sz);
  for(int i = 1; i <= sz; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    arr[i] = make_pair(u, v);
  }
  x %= 4;
  for(int st = 1; st <= x; ++st){
    for(int i = 1; i <= sz; ++i){
      pair < int, int > point = make_pair(arr[i].second, n - arr[i].first + 1);
      arr[i] = point;
    }
    swap(n, m);
  }
  y %= 2;
  if(y == 1){
    for(int i = 1; i <= sz; ++i){
      arr[i].second = m - arr[i].second + 1;
    }
  }
  z %= 4;
  for(int st = 1; st <= z; ++st){
    for(int i = 1; i <= sz; ++i){
      pair < int, int > point = make_pair(m - arr[i].second + 1, arr[i].first);
      arr[i] = point;
    }
    swap(n, m);
  }
  for(int i = 1; i <= sz; ++i){
    printf("%d %d\n", arr[i].first, arr[i].second);
  }
  return 0;
}