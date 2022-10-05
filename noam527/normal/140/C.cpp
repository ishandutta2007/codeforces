#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return a.first < b.first;
}

multimap<int, int>::iterator operator -(multimap<int, int>::iterator it, int num) {
	while (num--) it--;
	return it;
}

void smallsortlmao(vector<int> &a) {
	if (a[0] < a[1]) swap(a[0], a[1]);
	if (a[1] < a[2]) swap(a[1], a[2]);
	if (a[0] < a[1]) swap(a[0], a[1]);
}

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> ans;
	map<int, int> m;
	multimap<int, int> m2;
	for (int i = 0; i < n; i++) cin >> a[i], m[a[i]]++;
	if (m.size() < 3) {
		cout << 0 << endl;
		return 0;
	}
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++) m2.insert({ i->second, i->first });
	multimap<int, int>::iterator it1 = m2.end() - 3, it2 = m2.end() - 2, it3 = m2.end() - 1;
	while (it1->first > 0) {
		ans.push_back({ it1->second, it2->second, it3->second });
		auto cop1 = *it1, cop2 = *it2, cop3 = *it3;
		m2.erase(it1), m2.erase(it2), m2.erase(it3);
		m2.insert({ cop1.first - 1, cop1.second }), m2.insert({ cop2.first - 1, cop2.second }), m2.insert({ cop3.first - 1, cop3.second });
		it1 = m2.end() - 3, it2 = m2.end() - 2, it3 = m2.end() - 1;
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		smallsortlmao(i);
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
	return 0;
}