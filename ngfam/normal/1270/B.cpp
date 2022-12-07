#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector < int > a(n);
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    bool flag = false;
    for(int i = 1; i < n; ++i) {
      if(abs(a[i] - a[i - 1]) >= 2) {
        cout << "YES\n";
        cout << i << " " << i + 1 << "\n";
        flag = true;
        break;
      }
    }
    if(!flag) cout << "NO\n";
  }

  return 0;
}