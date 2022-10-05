#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int s, l;
map<int, vector<int>> m;
vector<int> ans;

int main() {
	fast;
	cin >> s >> l;
	for (int i = 1; i <= l; i++) m[i & -i].push_back(i);
	
	auto it = m.end();
	it--;
	while (s > 0 && it != m.begin()) {
		int ind = 0;
		while (ind < it->second.size() && s >= it->first)
			ans.push_back(it->second[ind++]), s -= it->first;
		it--;
	}
	if (it == m.begin() && s > 0) {
		int ind = 0;
		while (ind < it->second.size() && s >= it->first)
			ans.push_back(it->second[ind++]), s -= it->first;
	}
	if (s > 0) cout << -1 << endl;
	else {
		cout << ans.size() << endl;
		for (auto i : ans) cout << i << " "; cout << endl;
	}
}