#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(pair<string, vector<int>> &a, pair<string, vector<int>> &b) {
	if (a.first.size() != b.first.size())
		return a.first.size() < b.first.size();
	return a.first < b.first;
}
#define debug cout << "hi" << endl
int main() {
	ios::sync_with_stdio(0);
	int n, k, x, sz = -1;
	cin >> n;
	vector<pair<string, vector<int>>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> k;
		for (int j = 0; j < k; j++)
			cin >> x, a[i].second.push_back(--x);
		sz = max(sz, (int)a[i].first.size() + a[i].second[a[i].second.size() - 1]);
	}
	sort(a.begin(), a.end(), cmp);
	vector<int> oc(sz, -1);
	int p = 0;
	string ans = "";
	ans.resize(sz);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].second.size(); j++)
			if (oc[a[i].second[j]] == -1 || a[i].first.size() > a[oc[a[i].second[j]]].first.size())
				oc[a[i].second[j]] = i;
	}
	//for (int i = 0; i < oc.size(); i++) cout << oc[i] << " "; cout << endl;
	int left = 0, from = 0;
	for (p = 0; p < sz; p++) {
		if (oc[p] != -1 && a[oc[p]].first.size() > left) left = a[oc[p]].first.size(), from = oc[p];
		if (left == 0) {
			if (oc[p] == -1) ans[p] = 'a';
		}
		else {
			ans[p] = a[from].first[a[from].first.size() - left];
		}
		left = max(0, left - 1);
	}
	cout << ans << endl;
}