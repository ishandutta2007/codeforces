#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int INF = 1e9;
int n, m;
string s, t;
int dp[201][201][402];
int ch[201][201][402];
ar<int, 3> last[201][201][402];

ar<int, 3> transition(int i, int j, int k, char c) {
	if (k == 0 && c == ')') return {-1, -1, -1};
	int ni = i, nj = j, nk = k + (c == '(' ? +1 : -1);
	if (i < n && s[i] == c) ++ni;
	if (j < m && t[j] == c) ++nj;
	return {ni, nj, nk};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i <= 200; ++i) for (int j = 0; j <= 200; ++j) for (int k = 0; k <= 401; ++k) dp[i][j][k] = -1;
	cin >> s >> t;
	n = s.size(), m = t.size();
	dp[0][0][0] = 0;
	
	queue<ar<int, 3>> q;
	q.push({0, 0, 0});

	auto Consider = [&](ar<int, 3> b, ar<int, 3> u, char c, int d) {
		int i = u[0], j = u[1], k = u[2];
		if (i == -1 || k > n + m || dp[i][j][k] != -1) return;
		dp[i][j][k] = d;
		ch[i][j][k] = c;
		last[i][j][k] = b;
		q.push(u);
	};

	while(!q.empty()) {
		ar<int, 3> u = q.front(); q.pop();
		int i = u[0], j = u[1], k = u[2];
		Consider(u, transition(i, j, k, '('), '(', dp[i][j][k] + 1);
		Consider(u, transition(i, j, k, ')'), ')', dp[i][j][k] + 1);
	}

	assert(dp[n][m][0] < INF);
	string ans = "";
	int i = n, j = m, k = 0;
	while(i != 0 || j != 0 || k != 0) {
		ans.push_back(ch[i][j][k]);
		ar<int, 3> t = last[i][j][k];
		i = t[0], j = t[1], k = t[2];
	}
	reverse(ans.begin(), ans.end());
	assert(dp[n][m][0] == ans.size());
	cout << ans;
	return 0;
}