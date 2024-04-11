#include <bits/stdc++.h>

using namespace std;

const int N = 5555;

int n, m;
int a[N];
int f[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    double r;
    cin >> a[i] >> r;
  }
  int answer = 0;
  for(int i = 1; i <= n; ++i){
    f[i] = 1;
    for(int j = 1; j < i; ++j){
      if(a[i] >= a[j]){
        f[i] = max(f[i], f[j] + 1);
      }
    }
    answer = max(answer, f[i]);
  }
  cout << n - answer;
  return 0;
}