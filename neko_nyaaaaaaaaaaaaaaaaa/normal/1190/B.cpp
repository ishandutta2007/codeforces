#include <bits/stdc++.h>
using namespace std;
 
void win();
void lose();
 
void handle(vector<int> a) {
	int n = a.size();
	sort(a.begin(), a.end());
	
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			lose();
		}
	}
	
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (a[i] - i);
	}	
	if (sum % 2) {
		lose();
	} else {
		win();
	}
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	if (n == 1) {
		if (a[0] % 2 == 0) {
			lose();
		} else {
			win();
		}
	}
	
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			if (a[i] == 0) lose();
			a[i]--; 
			handle(a);
		}
	}
	sort(a.begin(), a.end());
	
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			lose();
		}
	}
	
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (a[i] - i);
	}	
	if (sum % 2) {
		win();
	} else {
		lose();
	}
 
	return 0;
}
 
void lose() {
	cout << "cslnb";
	exit(0);
}
 
void win() {
	cout << "sjfnb";
	exit(0);
}