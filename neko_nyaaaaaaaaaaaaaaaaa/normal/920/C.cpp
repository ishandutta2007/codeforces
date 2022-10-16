#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	
	set<int> se;
	se.insert(a[0]);
	for (int i = 0; i < n-1; i++) {
		if (s[i] == '1') {se.insert(a[i+1]); continue;}
		
		for (int j = i - se.size() + 1; j <= i; j++) {
			if (se.count(j+1) == 0) {cout << "NO"; return 0;}
		}
		se.clear();
		se.insert(a[i+1]);
		
	}
	
	for (int i = n - se.size() + 1; i <= n; i++) {
		if (se.count(i) == 0) {cout << "NO"; return 0;}
	}
	cout << "YES";
	
	
	return 0;
}