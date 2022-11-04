#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1e6 + 123;

char c[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  int n, k;
  cin >> n >> k;
  
  if (n < k) {
    cout << "-1\n";
    return 0;
  }
  
  if (k == 1) {
    if (n == 1) {
      cout << "a\n";
    } else {
      cout << "-1\n";
    }
    
    return 0;
  }
  
  for (int i = n - (k - 2), j = 0; i < n; i++, j++) {
    c[i] = 'c' + j;
  }
  
  for (int i = 0; i < n - (k - 2); i++) {
    if (i & 1) c[i] = 'b';
    else c[i] = 'a';
  }
  
  for (int i = 0; i < n; i++) cout << c[i];
  cout << "\n";
  
  return 0;
}