#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
	long n, x;
	cin >> n;
	vector<long> a(200001, 300000);
	for (long i = 1; i <= n; i++) {
	      cin >> x;
	      a[x] = i;
	}
	long ans, mi = 300000;
	for (long i = 0; i < 200001; i++) {
	      if (a[i] < mi) {mi = a[i]; ans = i;} 
	}
	cout << ans;
	
	return 0;
}