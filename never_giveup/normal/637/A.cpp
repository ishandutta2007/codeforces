#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 1;

int q[maxn], n;

int main(){
  cin >> n;
  int v = 0, ans;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    q[x]++;
    if (q[x] > v)
      v = q[x], ans = x;
  }
  cout << ans;
}