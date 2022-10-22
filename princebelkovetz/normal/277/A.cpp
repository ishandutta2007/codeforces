#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define debug(x) cout << #x << " is " << x << "\n";
using namespace std;
bool used[110];
void dfs(int i, vector <vector <int>>& ppl) {
	used[i] = true;
	set <int> langs;
	for (int j = 0; j < ppl[i].size(); ++j) {
		langs.insert(ppl[i][j]);
	}
	for (int j = 0; j < ppl.size(); ++j) {
		if (j == i or used[j]) continue;
		//debug(j);
		for (int f = 0; f < ppl[j].size(); ++f) {
			if (langs.find(ppl[j][f]) != langs.end()) {
				dfs(j, ppl);
				break;
			}
		}
	}
}
int main() {
	int n, m; cin >> n >> m;
	vector <vector <int>> ppl (n);
	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;  cin >> x;
			ppl[i].push_back(x);
		}
	}
	int ans = -1;
	bool c = true;
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		if (ppl[i].size()) c = false;
		dfs(i, ppl);
		++ans;
	}
	if (c) ++ans;
	cout << ans << endl;
	
}