#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<int> v[202020];
int s[202020];
vector<set<int>> q;
int z[202020];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) cin >> s[i];
	q.push_back({1});
	z[1] = 1;
	int k = 0;
	int i = 1;
	while (true) {
		if (!q[k].size()) k++;
		if (q[k].size() && q[k].count(s[i])) {
			set<int> u;
			q[k].erase(s[i]);
			for (auto x : v[s[i]]) {
				if (z[x]) continue;
				z[x] = 1;
				u.insert(x);
			}
			if (u.size()) q.push_back(u);
			i++;
		} else {
			cout << "No\n";
			return 0;
		}
		if (i == n+1) {
			cout << "Yes\n";
			return 0;
		}
	}
}