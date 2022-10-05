#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> st, en;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		vector<int> a(l);
		for (auto &j : a) cin >> j;
		bool bad = true;
		for (int j = 1; j < a.size(); j++)
			if (a[j - 1] < a[j]) bad = false;
		if (bad) {
			st.push_back(a[0]);
			en.push_back(a.back());
		}
	}
	sort(st.begin(), st.end());
	sort(en.begin(), en.end());
	ll tot = (ll)n * n;
	int nxt = 0;
	for (auto &i : en) {
		while (nxt < st.size() && st[nxt] <= i) nxt++;
		tot -= nxt;
	}
	cout << tot << endl;
}