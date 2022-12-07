#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n; cin >> n;

  int m = 0;
  while(m + m - 1 < n) ++m;

  cout << m << endl;

  int x = 1, y = 1;
  for(int i = 1; i <= n; ++i) {
    cout << x << " " << y << endl;
    if(x < m) ++x;
    else ++y;
  }

  return 0;
}