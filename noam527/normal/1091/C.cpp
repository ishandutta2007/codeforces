#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
using namespace std;

void debug(string names) {
	cout << '\n';
}
template<typename A1, typename... A2>
void debug(string names, A1 par, A2... left) {
	int pos = 0;
	for (; pos < names.size() && names[pos] != ' ' && names[pos] != ','; pos++)
		cout << names[pos];
	cout << ": " << par << "  ";
	while (pos < names.size() && (names[pos] == ' ' || names[pos] == ',')) {
		pos++;
	}
	names.erase(names.begin(), names.begin() + pos);
	debug(names, left...);
}

ll n;
vector<ll> a, ans;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			a.push_back(i);
			a.push_back(n / i);
		}
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());

	for (auto &i : a) {
		ans.push_back((n - i) * (n / i) / 2 + n / i);
	}
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	for (const auto &i : ans) cout << i << " "; cout << '\n';
}