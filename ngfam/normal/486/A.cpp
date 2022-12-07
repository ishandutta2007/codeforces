#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		//freopen("1.out", "w", stdout);
	#endif

  long long n; cin >> n;
  if(n % 2 == 0) cout << n / 2;
  else{
    cout << (n + 1) / 2 - n - 1;
  }

	return 0;
}