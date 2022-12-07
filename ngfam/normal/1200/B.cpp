#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int t; cin >> t;
  while(t--) {
    int n, m, k;
    cin >> n >> m >> k;

    vector < int > h(n);
    for(auto &x : h) cin >> x;

    for(int i = 0; i < n - 1; ++i) {
      if(h[i] >= h[i + 1] - k) {
        int  x = max(h[i + 1] - k, 0);
        m += h[i] - x;
      }
      else {
        if(m < h[i + 1] - k - h[i]) {
          m = -1;
          break;
        }
        else m -= h[i + 1] - k - h[i];
      }
    }

    if(m >= 0) cout << "YES";
    else cout << "NO";
    cout << endl;
  }

  return 0;
}