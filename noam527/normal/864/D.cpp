#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 149;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, c = 0;
vector<vector<int>> a;
vector<int> f, b, col, haveto, cnt;

int main() {
	fast;
	cin >> n;
	a.resize(n);
	b.resize(n);
	col.resize(n, 0);
	haveto.resize(n, 0);
	cnt.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
		a[b[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) if (a[i].size() == 0) f.push_back(i);
	for (int i = 0; i < n; i++) cnt[i] = a[i].size();
	sort(f.begin(), f.end());

	for (int i = 0; i < n; i++) {
		if (a[i].size() > 1) {
			for (int j = 0; j < a[i].size(); j++)
				col[a[i][j]] = 1;
		}
	}
	cout << f.size() << endl;
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (col[i] && cnt[b[i]] > 1 && p < f.size()) {
			if (haveto[i]) cnt[b[i]]--, b[i] = f[p++];
			else {
				if (b[i] > f[p]) cnt[b[i]]--, b[i] = f[p++];
				else {
					for (int j = 0; j < a[b[i]].size(); j++)
						haveto[a[b[i]][j]] = 1;
				}
			}
		}
	}
	for (auto &i : b) cout << i + 1 << " "; cout << endl;
}