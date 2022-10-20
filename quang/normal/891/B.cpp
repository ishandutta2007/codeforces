#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n;
int id[N];
int res[N];
int a[N];

bool cmp(int u, int v) {
	return a[u] < a[v];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		id[i] = i;
	}
	
	sort(id, id + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			res[id[i]] = a[id[0]];
		} else {
			res[id[i]] = a[id[i + 1]];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
	return 0;
}