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

int a, b, c;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> a >> b >> c;
	int mx = 0;
	for (int i = 1; i <= a; i++) {
		if (i <= a && i + 1 <= b && i + 2 <= c) mx = max(mx, 3 * (i + 1));
	}
	finish(mx);
}