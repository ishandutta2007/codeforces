#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;
  vector < int > a(n + n);

  int sum = 0;
  for(int i = 0; i < n + n; ++i) {
    cin >> a[i];
    if(i < n) sum += a[i];
    else sum -= a[i];
  }

  if(sum != 0) {
    for(int x : a) cout << x << " ";
  }
  else {
    for(int i = 0; i < n; ++i) {
      for(int j = n; j < n + n; ++j) {
        if(a[i] != a[j]) {
          swap(a[i], a[j]);
          for(int k = 0; k < n + n; ++k) {
            cout << a[k] << " ";
          }
          return 0;
        }
      }
    }
    cout << -1;
  }

  return 0;
}