#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

const int N = 1505;

int n, m;
int a[N][N], b[N][N];
vector<int> need[N], give[N];
int cnt[N] = {};
vector<int> result;

vector<int> cur;
vector<int> pos;
int col;

bool cmp(int r1, int r2) {
	if (a[r1][col] != a[r2][col]) return a[r1][col] < a[r2][col];
	return pos[r1] < pos[r2];
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> a[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> b[i][j];

	// S
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i - 1][j] > b[i][j])
				need[i].push_back(j), cnt[j]++;
			if (b[i - 1][j] != b[i][j])
				give[j].push_back(i);
		}
	}

	if (OO) {
		for (int i = 0; i < n; i++) {
			cout << "need:\n";
			for (const auto &j : need[i]) cout << j << " "; cout << '\n';
			for (const auto &j : give[i]) cout << j << " "; cout << '\n';
			cout << '\n';
		}
	}

	queue<int> q;
	for (int j = 0; j < m; j++)
		if (cnt[j] == 0) q.push(j);
	while (q.size()) {
		int j = q.front();
		q.pop();
		result.push_back(j);
		//cout << "queue: " << j << '\n';
		for (const auto &i : give[j]) {
			for (const auto &col : need[i]) {
				cnt[col]--;
				if (cnt[col] == 0) q.push(col);
			}
			need[i].clear();
		}
	}
	//for (const auto &i : result) cout << i << " "; cout << '\n';

	cur.resize(n);
	pos.resize(n);
	for (int i = 0; i < n; i++)
		cur[i] = pos[i] = i;
	reverse(result.begin(), result.end());
	for (const auto &i : result) {
		col = i;
		sort(cur.begin(), cur.end(), cmp);
		for (int j = 0; j < n; j++)
			pos[cur[j]] = j;
	}
	//for (const auto &i : cur) cout << i << " "; cout << '\n';
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (a[cur[i]][j] != b[i][j]) {
			cout << "-1\n";
			return;
		}
	}
	cout << result.size() << '\n';
	for (const auto &i : result) cout << 1 + i << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}