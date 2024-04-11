#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define last(X) (X)[(X).size() - 1]
typedef long long ll;
using namespace std;

void show(multiset<ll> &a) {
	cout << "multiset:" << endl;
	for (auto i = a.begin(); i != a.end(); i++) cout << *i << " "; cout << endl;
}

void show(vector<pair<ll, ll>> &a) {
	cout << "vector<pair>: " << endl;
	for (auto i : a) cout << i.first << " " << i.second << endl;
}

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
	return a.first < b.first;
}

int main() {
	ll n, p, t, w, mn = 1e9;
	cin >> n >> p >> w;
	multiset<ll> higher;
	vector<pair<ll, ll>> lower;
	for (int i = 0; i < n - 1; i++) {
		cin >> t >> w;
		if (t > p) higher.insert(w - t + 1);
		else lower.push_back({ t, w - t + 1 });
	}
	sort(lower.begin(), lower.end(), cmp);
	mn = higher.size() + 1;
	while (p >= 0 && higher.size() > 0) {
		p -= *higher.begin();
		higher.erase(higher.begin());
		if (p < 0) break;
		while (lower.size() > 0 && p < last(lower).first)
			higher.insert(last(lower).second), lower.pop_back();
		mn = min(mn, (ll)higher.size() + 1);
	}
	cout << mn << endl;
}