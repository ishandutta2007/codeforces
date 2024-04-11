#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n, l, r; cin >> n >> l >> r;

  vector < int > a(n);

  int minsum = 0, maxsum = 0;

  for(int i = 0; i < r; ++i) {
    maxsum += (1 << i);
  }

  maxsum += (1 << (r - 1)) * (n - r);

  for(int i = 0; i < l; ++i) {
    minsum += (1 << i);
  }

  minsum += (n - l);

  cout << minsum << " " << maxsum << endl;

  return 0;
}