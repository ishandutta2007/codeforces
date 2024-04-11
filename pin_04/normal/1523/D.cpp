#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 5; 

string s[N];

int cnt[1 << 15];
int numbit[1 << 15];
int n,m,p;

int rand(int l, int r) {
	return l + rd() % (r - l + 1);
}

int getbit(int x, int i) {
	return (x >> i) & 1;
}

int bit(int x) {
	return (1 << x);
}

int solve(int x) {
	vector <int> pos;

	for (int i = 0; i < m; i++)
		if (s[x][i] == '1')
			pos.push_back(i);

	for (int i = 0; i < bit(p); i++)
		cnt[i] = 0;

	for (int i = 1; i <= n; i++) {
		int mask = 0;
		for (int j = 0; j < (int) pos.size(); j++)
			if (s[i][pos[j]] == '1')
				mask |= bit(j);
		cnt[mask]++;
	}

	int res = 0;
	for (int i = 0; i < p; i++)
	for (int mask = bit(p) - 1; mask >= 0; mask--) {
		if (!getbit(mask, i))
				cnt[mask] += cnt[mask ^ bit(i)];
		if (cnt[mask] >= (n + 1) / 2 && numbit[mask] > numbit[res]) 
			res = mask;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) 
		cin >> s[i];

	for (int i = 0; i < bit(p); i++)
		numbit[i] = __builtin_popcount(i);

	int ans = 0;
	int posans = 1;
	for (int i = 1; i <= 60; i++) {
		int pos = rand(1, n);
		int res = solve(pos);
		if (numbit[ans] < numbit[res]) {
			posans = pos;
			ans = res;
		}
	}

	for (int i = 0, cnt = 0; i < m; i++) {
		if (s[posans][i] == '1') {
			cout << getbit(ans, cnt);
			cnt++;
		} else
			cout << 0;
	}

	return 0;
}