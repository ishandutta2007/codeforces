#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, m;

int ask1(int i) {
	string s(m, '0');
	s[i] = '1';
	cout << "? " << s << endl;
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}
int ask2(const vector<int> &a) {
	string s(m, '0');
	for (auto &i : a) s[i] = '1';
	cout << "? " << s << endl;
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}
void answer(int x) {
	cout << "! " << x << endl;
	cout.flush();
}

void solve() {
	cin >> n >> m;
	vector<pair<int, int>> w(m);
	for (int i = 0; i < m; i++) {
		w[i] = { ask1(i), i };
	}
	sort(w.begin(), w.end());
	int cursum = 0;
	vector<int> t;
	t.push_back(w[0].second);
	cursum = w[0].first;
	for (int i = 1; i < m; i++) {
		t.push_back(w[i].second);
		int tmp = ask2(t);
		if (cursum + w[i].first > tmp) t.pop_back();
		else cursum = tmp;
	}
	answer(cursum);
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}