#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> a(5004);
bool flag = 0;

void dfs(int now, int init, int size) {
	if (size == 3) {
		if (a[now] == init && now != init) {flag = 1;}
		return;
	}
	dfs(a[now], init, size+1);
}

int main() {
	ios::sync_with_stdio(0);
	// cout << fixed << setprecision(12);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, i, 1);
		if (flag) {cout << "YES"; return 0;}
	}
	cout << "NO";
	
	return 0;
}