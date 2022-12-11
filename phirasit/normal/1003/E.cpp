#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;

vector<pii> edges;
int n;

void dfs(int u, int dis, int k, int &cnt, bool flag) {
	if (dis == 0) return;
	for (int i = 0; i < k-1-flag && cnt < n; ++i) {
		int id = ++cnt;
		edges.push_back(pii(u, id));
		dfs(id, dis-1, k, cnt, false);
	}
}
int main() {

	cin.sync_with_stdio(false);
	cin.tie(0);

	int d, k;
	cin >> n >> d >> k;

	if (k == 1) {
		if (d > 1) {
			cout << "NO" << endl;
			return 0;
		}
	}

	int cnt = d+1;
	for (int i = 1; i <= d; ++i) {
		edges.push_back(pii(i, i+1));
	}
	for (int i = 2; i <= d && cnt < n; ++i) {
		int dis = min(i-1, d-i+1);
		dfs(i, dis, k, cnt, true);
	}

	if (cnt != n) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (const pii& e : edges) {
			cout << e.first << " " << e.second << "\n";
		}
	}

	return 0;
}