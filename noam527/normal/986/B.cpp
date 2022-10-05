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

int n;
vector<int> a, v;

void work(int x) {
	if (v[x]) return;
	v[x] = 1;
	work(a[x]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int cnt = 0;
	cin >> n;
	a.resize(n);
	v.resize(n, 0);
	for (auto &i : a) cin >> i, --i;
	for (int i = 0; i < n; i++)
		if (!v[i]) {
			work(i);
			cnt++;
		}
	cnt = n - cnt;
	if ((cnt & 1) == ((3 * n) & 1)) cout << "Petr" << '\n';
	else cout << "Um_nik" << '\n';
}