#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
	long long sum = 0;
	vector<long long> a(6);
	for (long i = 0; i < 6; i++) {
	      cin >> a[i];
	      sum += a[i];
	}
	if (sum % 2) {cout << "NO"; return 0;}
	sum /= 2;
	for (long i = 0; i < 4; i++) {
	      for (long j = i+1; j < 5; j++) {
	            for (long k = j+1; k < 6; k++) {
	                  if (a[i] + a[j] + a[k] == sum) {cout << "YES"; return 0;}
	            }
	      }
	}
	cout << "NO";
	
	return 0;
}