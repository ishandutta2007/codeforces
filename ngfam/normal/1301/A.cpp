#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    string a, b, c;
    cin >> a >> b >> c;
    string ans = "YES";
    for(int i = 0; i < a.size(); ++i) {
      if(c[i] != b[i] && c[i] != a[i]) ans = "NO";
    }
    cout << ans << endl;
  }

  return 0;
}