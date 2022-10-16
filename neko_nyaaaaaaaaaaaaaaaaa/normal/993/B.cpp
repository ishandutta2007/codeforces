#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		
		if (a[i].first > a[i].second) {
			swap(a[i].first, a[i].second);
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i].first >> b[i].second;
		
		if (b[i].first > b[i].second) {
			swap(b[i].first, b[i].second);
		}
	}
	
	vector<int> po(10);
	
	int p1 = 1;
	for (int i = 0; i < n; i++) {
		vector<int> flag(2);
		pair<int, int> k = a[i];
		for (int j = 0; j < m; j++) {
			pair<int, int> u = b[j];
			
			if (u.first == k.first && u.second == k.second) continue;
			
			if (k.first == u.first || k.first == u.second) {flag[0] = 1;}
			if (k.second == u.first || k.second == u.second) {flag[1] = 1;}
		}
		
		if (flag[0] && flag[1]) {p1 = 0;}
		if (flag[0]) {po[a[i].first] = 1;}
		if (flag[1]) {po[a[i].second] = 1;}
	}
	
	int p2 = 1;
	for (int i = 0; i < m; i++) {
		vector<int> flag(2);
		pair<int, int> k = b[i];
		for (int j = 0; j < n; j++) {
			pair<int, int> u = a[j];
			
			if (u.first == k.first && u.second == k.second) continue;
			
			if (k.first == u.first || k.first == u.second) {flag[0] = 1;}
			if (k.second == u.first || k.second == u.second) {flag[1] = 1;}
		}
		
		if (flag[0] && flag[1]) {p2 = 0;}
		if (flag[0]) {po[b[i].first] = 1;}
		if (flag[1]) {po[b[i].second] = 1;}
	}
	
	if (!p1 || !p2) {cout << -1; return 0;}
	
	int ans = -1;
	for (int i = 0; i < 10; i++) {
		if (po[i]) {
			if (ans == -1) ans = i;
			else {cout << 0; return 0;}
		}
	}
	
	cout << ans;
	
	return 0;
}