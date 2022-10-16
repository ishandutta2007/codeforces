#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n,x;
	cin >> n;
	vector<int> a(101, 0);
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x]++;
	}
	vector<int> b = a;
	sort(a.begin(), a.end(), greater<int>());
	if (a[0] == a[1] && a[2] == 0) {cout << "YES" << endl;
		for (int i = 0; i < 101; i++) {
			if (b[i]) {cout << i << " ";}
		}
	} else {cout << "NO";}
	
	
	return 0;
}