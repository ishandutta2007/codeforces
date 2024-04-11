#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int T; cin >> T;
  while(T--) {
    int a, b, n;
    cin >> a >> b >> n;

    if(n < 2) {
      cout << (n == 0 ? a : b) << endl;
    }
    else {
      int ret = 0;
      if(n % 3 != 1) ret ^= a;
      if(n % 3 != 0) ret ^= b;
      cout << ret << endl;
    }
  }

  return 0;
}