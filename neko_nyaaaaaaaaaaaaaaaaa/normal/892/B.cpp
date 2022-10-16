#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
	long long n;
	cin >> n;
	vector<long long> a(n);
	for (long long i = 0; i < n; i++) {
	      cin >> a[i];
	}
	long long i = n-1;
	long long kill = a[i];
	vector<bool> ans(n, true);
	while (i) {
	      kill = max(kill, a[i]);
	      if (kill) {
	            i--;
	            ans[i] = false;
	            kill--;
	      } else {
	            i--;
	      }
	}
	long long k = 0;
	for (long long j = 0; j < n; j++) {
	      if (ans[j]) k++;
	}
	cout << k;
	
	return 0;
}