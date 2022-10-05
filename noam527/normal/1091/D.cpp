#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
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

ll f[1000005];

ll calc(ll x) {
	if (x <= 2) return 0;
	ll rtn = x * (f[x - 1] - 1) % md;
	rtn = (rtn + x * calc(x - 1)) % md;
	return rtn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	f[0] = 1;
	for (int i = 1; i < 1000005; i++)
		f[i] = f[i - 1] * i % md;
	int n;
	cin >> n;
	ll ans = f[n];
	ans = (ans + calc(n)) % md;
	finish(ans);
}