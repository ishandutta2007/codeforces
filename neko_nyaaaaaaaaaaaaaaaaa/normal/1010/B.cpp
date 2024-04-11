#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int read() {
	int n;
	cin >> n;
	if (n == 0) exit(0);
	if (n == -2) exit(0);
	return n;
}

int main() {
	//ios::sync_with_stdio(0); cin.tie(0);
	
	int m, n;
	cin >> m >> n;
	
	if (m == 1) {cout << 1 << endl; return 0;}
	if (m == 2) {
	      cout << 1 << endl;
	      int x = read();
	      cout << 2 << endl;
	}
	
	vector<int> s;
	
	for (int i = 0; i < n; i++) {
		cout << 1 << endl;
		int ans = read();
		
		if (ans == 1) {s.push_back(1);}
		else {s.push_back(0);}
	}
	
	int lo = 1, hi = m, i = -1;
	while (lo < hi) {
		i++;
		i %= n;
		int mid = (lo + hi + 1)/2;
		cout << mid << endl;
		
		int ans = read();
		
		if ((ans == 1 && s[i]) || (ans == -1 && s[i] == 0)) {
			// mid < answer
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	
	cout << lo << endl;
	
	return 0;
}