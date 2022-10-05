#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 9e18;
const int OO = 0;
using namespace std;

int n;
string s;
vector<int> ZZ, MM;

bool palin(int l, int r) {
	l *= 2, r *= 2;
	return MM[(l + r) / 2] + (l + r) / 2 >= r;
}
bool prefixsuffix(int len) {
	if (len == n) return true;
	return ZZ[n - len] == len;
}

vector<int> algoZ() {
	vector<int> Z(n, 0);
	int j = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r)
			Z[i] = min(r - i + 1, Z[i - j]);
		while (i + Z[i] < n && s[i + Z[i]] == s[Z[i]])
			Z[i]++;
		if (r < Z[i])
			j = i, r = j + Z[i] - 1;
	}
	return Z;
}
vector<int> algoM() {
	vector<int> M(2 * n - 1, 0);
	int j = -1, r = -1;
	for (int i = 1; i < 2 * n - 2; i++) {
		if (i <= r)
			M[i] = M[2 * j - i];
		while (i + M[i] + 1 < M.size() && i - M[i] - 1 >= 0 && ((i + M[i] + 1) % 2 == 1 || s[(i + M[i] + 1) / 2] == s[(i - M[i] - 1) / 2]))
			M[i]++;
		if (r < M[i])
			j = i, r = j + M[i];
	}
	return M;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	n = s.size();
	bool found = false;
	for (int i = 1; i < n; i++)
		if (2 * i + 1 != n)
			if (s[i] != s[0])
				found = true;
	if (!found) finish("Impossible");

	ZZ = algoZ();
	MM = algoM();

	for (int i = 1; i <= n; i++)
		if (n % i == 0 && n / i % 2 == 0) {
			if (OO) cout << "i = " << i << '\n';
			if (!palin(0, i - 1) && prefixsuffix(2 * i)) finish(1);
		}
	finish(2);
}