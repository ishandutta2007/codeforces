#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
	long long n;
	long long sum = 0;
	cin >> n;
	vector<long long> a(n), b(n);
	for (long long i = 0; i < n; i++) {
	      cin >> a[i];
	      sum += a[i];
	}
	for (long long i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	if (sum <= (b[n-1] + b[n-2])) {cout << "YES";} else {cout << "NO";}
	
	
	
	return 0;
}