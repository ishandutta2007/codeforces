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

int n;
vector<pair<int, int>> a, b;
map<pair<int, int>, int> M;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto &i : a) cin >> i.first >> i.second;
	for (auto &i : b) cin >> i.first >> i.second;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		M[{a[i].first + b[j].first, a[i].second + b[j].second}]++;
	for (auto &i : M) {
		if (i.second == n) {
			cout << i.first.first << " " << i.first.second << '\n';
			return 0;
		}
	}

}