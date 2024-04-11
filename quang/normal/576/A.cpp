#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N];
int n;
vector <int> x;

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  //freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  cin >> n;
  int res = 0;
  for (int i = 2; i <= n; i++) {
    if (!a[i]) {
      for (int j = i; j <= n; j *= i) {
        res++;
        x.push_back(j);
      }
      for (int j = i + i; j <= n; j+= i) {
        a[j] = 1;
      }
    }
  }
  cout << res << endl;
  for (int i : x) {
    cout << i << " ";
  }
  return 0;
}