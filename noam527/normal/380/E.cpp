#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#define toend cin.ignore(); cin.get(); return 0
#define finish(X) return cout << (X) << '\n'
#define CHECK cout << "ok\n"
typedef long long ll;
typedef long double ldb;
const int OO = 0;
const int inf = 2e9 + 7;
using namespace std;

const int lim = 60;

int n;
vector<pair<int, int>> a;
set<int> S;
vector<int> R, L;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	ldb ans = 0;

	for (auto &i : a) {
		if (OO) cout << "adding " << i.first << " " << i.second << '\n';
		L.clear();
		R.clear();
		int lst = i.second, iter;

		auto it = S.upper_bound(lst);
		iter = lim;
		while (iter > 0 && it != S.end()) {
			iter--;
			R.push_back(*it - lst);
			lst = *it;
			it++;
		}
		if (iter && it == S.end())
			R.push_back(n - lst);

		lst = i.second;
		it = S.lower_bound(lst);
		iter = lim;
		if (it != S.begin()) {
			it--;
			while (iter > 0 && it != S.begin()) {
				iter--;
				L.push_back(lst - *it);
				lst = *it;
				it--;
			}
			if (iter && it == S.begin()) {
				iter--;
				L.push_back(lst - *it);
				lst = *it;
			}
		}
		if (iter && it == S.begin()) L.push_back(lst + 1);

		if (OO) {
			cout << "L ";
			for (const auto &j : L) cout << j << " "; cout << '\n';
			cout << "R ";
			for (const auto &j : R) cout << j << " "; cout << '\n';
		}

		ldb suml = 0, coef = 0.5, add = 0;
		for (int i = 0; i < L.size(); i++) {
			suml += coef * L[i];
			coef /= 2;
		}
		for (int i = 0; i < R.size(); i++) {
			add += R[i] * suml;
			suml /= 2;
		}
		ans += i.first * add;
		if (OO) cout << "new ans " << ans << '\n';
		S.insert(i.second);
	}
	cout.precision(10);
	cout << ans / n / n << '\n';
	toend;
}