#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
  int n; cin >> n;
  vector < int > a(n); 
  for(int i = 0; i < n; ++i) cin >> a[i];

  for(int mask = 0; mask < (1 << n); ++mask) {
    int sum = 0;
    for(int i = 0; i < n; ++i) if(mask & (1 << i)) {
      sum += a[i];
    }
    else sum -= a[i];

    if(sum % 360 == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

	return 0;
}