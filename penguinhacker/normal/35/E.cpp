#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n;
map<int, vector<int>> upd;
multiset<int> cur;
vector<ar<int, 2>> ans;

void add(int x, int y) {
	if (ans.size()>2&&y==ans.end()[-1][1]&&y==ans.end()[-2][1])
		ans.pop_back();
	ans.push_back({x, y});
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n;
	for (int i=0; i<n; ++i) {
		int h, l, r;
		cin >> h >> l >> r;
		upd[l].push_back(h);
		upd[r].push_back(-h);
	}
	cur.insert(0);
	for (auto& x : upd) {
		add(x.first, *cur.rbegin());
		for (int h : x.second) {
			if (h>0)
				cur.insert(h);
			else
				cur.erase(cur.find(-h));
		}
		add(x.first, *cur.rbegin());
	}
	cout << ans.size() << "\n";
	for (ar<int, 2> a : ans)
		cout << a[0] << " " << a[1] << "\n";
	return 0;
}