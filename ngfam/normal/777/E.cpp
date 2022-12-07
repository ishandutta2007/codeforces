#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

struct tower{
  int a;
  int b;
  int h;
}arr[N];

struct fenwick{
  long long bit[N];
  void upd(int i, long long val){
    for(; i < N; i += i & -i){
      bit[i] = max(bit[i], val);
    }
  }
  long long ask(int i){
    long long result = 0;
    for(; i > 0; i &= i - 1){
      result = max(result, bit[i]);
    }
    return result;
  }
}fwt;

int n;
long long f[N];
vector < int > small;

bool cmp(tower u, tower v){
  if(u.b == v.b){
    return u.a > v.a;
  }
  return u.b > v.b;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen("1.out", "W", stdout);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int a, b, h;
    scanf("%d%d%d", &a, &b, &h);
    arr[i] = {a, b, h};
    small.push_back(a);
    small.push_back(b);
  }
  sort(small.begin(), small.end());
  small.resize(unique(small.begin(), small.end()) - small.begin());
  for(int i = 1; i <= n; ++i){
    arr[i].a = lower_bound(small.begin(), small.end(), arr[i].a) - small.begin() + 1;
    arr[i].b = lower_bound(small.begin(), small.end(), arr[i].b) - small.begin() + 1;
  }
  sort(arr + 1, arr + n + 1, cmp);
  long long answer = 0;
  for(int i = 1; i <= n; ++i){
    f[i] = arr[i].h + fwt.ask(arr[i].b - 1);
    fwt.upd(arr[i].a, f[i]);
    answer = max(answer, f[i]);
  }
  cout << answer;
  return 0;
}