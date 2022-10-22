#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
bool used[110];
void dfs(int i, vector <pair <int, int>>& dots) {
	used[i] = true;
	for (int j = 0; j < dots.size(); ++j) {
		if (j == i or used[j]) continue;
		if (dots[j].first == dots[i].first or dots[j].second == dots[i].second) dfs(j, dots);
	}
}
int main() {
	int n; cin >> n;
	vector <pair <int, int>> dots;
	for (int i = 0; i < n; ++i) {
		int u, v; cin >> u >> v;
		dots.push_back({ u, v });
	}
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		dfs(i, dots);
		++ans;
	}
	cout << ans << endl;
	
}