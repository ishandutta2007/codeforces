#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;


int n, nn;
vector<int> a;
vector<int> dis;
vector<vector<int>> op;

void bfs(int setn, int leave) {
	nn = setn;
	dis.clear();
	dis.resize((1 << nn), -1);
	queue<int> q;
	for (int i = 0; i <= leave; i++) {
		q.push(i);
		dis[i] = 0;
	}
	int t;
	while (!q.empty()) {
		t = q.front(), q.pop();
		for (int x = 0, z; x < nn; x++) for (int y = x + 1; 2 * y - x < nn; y++) {
			z = 2 * y - x;
			z = (t ^ (1 << x) ^ (1 << y) ^ (1 << z));
			if (dis[z] == -1) {
				dis[z] = 1 + dis[t];
				q.push(z);
			}
		}
	}
}

int solvesmall(int val) {
	int curr = dis[val];
	if (curr == -1) return -1;
	int rtn = 0;
	while (curr > 0) {
		for (int x = 0, z; x < nn; x++) for (int y = x + 1; 2 * y - x < nn; y++) {
			z = 2 * y - x;
			z = (val ^ (1 << x) ^ (1 << y) ^ (1 << z));
			if (dis[z] < curr) {
				curr = dis[z];
				val = z;
				op.push_back({ x, y, 2 * y - x });
				rtn++;
			}
		}
	}
	return rtn;
}

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;

	bfs(13, 127);
	int bin = 0;

	while (n >= 14) {
		bin = 0;
		for (int i = n - 13; i < n; i++)
			if (a[i])
				bin += (1 << (i - (n - 13)));
		int add = solvesmall(bin);
		for (int i = 1; i <= add; i++) {
			for (auto &j : op[op.size() - i]) {
				j += n - 13;
				a[j] ^= 1;
			}
		}
		n -= 6;
	}

	bfs(n, 0);

	bin = 0;
	for (int i = 0; i < n; i++) if (a[i]) bin += (1 << i);
	if (solvesmall(bin) == -1) finish("NO");
	cout << "YES" << endl;
	cout << op.size() << endl;
	for (const auto &i : op) {
		for (const auto &j : i) cout << 1 + j << " ";
		cout << endl;
	}
}