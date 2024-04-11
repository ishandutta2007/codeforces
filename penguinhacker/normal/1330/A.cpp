#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, x;
bool visited[1000];

void solve() {
	memset(visited, 0, sizeof(visited));
	cin >> n >> x;
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		visited[a]=1;
	}
	int ref = 1;
	while (x>0 || visited[ref]) {
		if (!visited[ref])
			x--;
		ref++;
	}
	cout << --ref << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}