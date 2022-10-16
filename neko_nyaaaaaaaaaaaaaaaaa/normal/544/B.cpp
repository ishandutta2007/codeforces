#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	if (k > (n*n + 1)/2) {cout << "NO"; return 0;}
	cout << "YES\n";
	
	for (int i = 0; i < n; i++) {
	      for (int j = 0; j < n; j++) {
	            if ((i+j) % 2 == 0 && k) {
	                  k--;
	                  cout << 'L';
	            } else {
	                  cout << 'S';
	            }
	      }
	      cout << '\n';
	}
	
	return 0;
}