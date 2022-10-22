#include <bits/stdc++.h>
using namespace std;

int n, k;
string s[2];
int height[100000][2];

void solve() {
	memset(height, 0x3f, sizeof(height));
	queue<pair<int, int>> q;
	q.push({0, 0});
	height[0][0] = -1;

	while (!q.empty()) {
		int p=q.front().first, side=q.front().second;
		int w=height[p][side];
		q.pop();
		if (p+k>=n) {
			cout << "YES";
			exit(0);
		}
		if (p-1>=0&&height[p-1][side]>1000000&&s[side][p-1]=='-'&&w+1<p-1) {
			q.push({p-1, side});
			height[p-1][side] = w+1;
		}
		if (height[p+1][side]>1000000&&s[side][p+1]=='-'&&w+1<p+1) {
			q.push({p+1, side});
			height[p+1][side] = w+1;
		}
		if (height[p+k][side^1]>1000000&&s[side^1][p+k]=='-'&&w+1<p+k) {
			q.push({p+k, side^1});
			height[p+k][side^1] = w+1;
		}
	}
	cout << "NO";
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	cin >> s[0] >> s[1];
	solve();
	return 0;
}