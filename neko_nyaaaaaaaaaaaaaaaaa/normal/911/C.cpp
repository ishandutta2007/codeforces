#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	vector<int> a(3);
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	do {
	      vector<bool> c(100000, 0);
	      for (int i = 0; i < 3; i++) {
		      for (int j = i+1; j < 100000; j += a[i]) {
		      	c[j] = 1;
	      	}
      	}
      	bool yes = 1;
      	for (int i = 1; i < 100000; i++) {
	         if (c[i] == 0) {yes = 0; break;}
      	}
      	if (yes) {cout << "YES"; return 0;}
	} while (next_permutation(a.begin(), a.end()));
	cout << "NO";
	
	return 0;
}