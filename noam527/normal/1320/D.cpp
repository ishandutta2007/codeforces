#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

const ll h1 = 31, h2 = 199;
const int md1 = 1e9 + 7, md2 = 1e9 + 9;

int n, q;
string s;
vector<int> pref, fi, dist;

int m;
vector<int> arr;

vector<ll> H1, H2, P1, P2;

int count(int l, int r) {
	if (l == 0) return pref[r];
	return pref[r] - pref[l - 1];
}

bool total(int x, int y, int len) {
	return count(x, x + len - 1) == count(y, y + len - 1);
}

void prep() {
	if (m == 1) return;
	P1.resize(m), P2.resize(m);
	P1[0] = P2[0] = 1;
	for (int i = 1; i < m; i++) {
		P1[i] = P1[i - 1] * h1 % md1;
		P2[i] = P2[i - 1] * h2 % md2;
	}

	H1.resize(m), H2.resize(m);
	H1[0] = H2[0] = arr[0];
	for (int i = 1; i < m - 1; i++) {
		H1[i] = (H1[i - 1] * h1 + arr[i]) % md1;
		H2[i] = (H2[i - 1] * h2 + arr[i]) % md2;
	}
}

ll hsh1(int l, int r) {
	if (l == 0) return H1[r];
	ll rtn = (H1[r] - P1[r - l + 1] * H1[l - 1]) % md1;
	if (rtn < 0) rtn += md1;
	return rtn;
}
ll hsh2(int l, int r) {
	if (l == 0) return H2[r];
	ll rtn = (H2[r] - P2[r - l + 1] * H2[l - 1]) % md2;
	if (rtn < 0) rtn += md2;
	return rtn;
}
bool check2(int x, int y, int len) {
	return hsh1(x, x + len - 1) == hsh1(y, y + len - 1) &&
		hsh2(x, x + len - 1) == hsh2(y, y + len - 1);
}

bool query(int x, int y, int cnt) {
	cnt--;
	if (cnt <= 0) return true;
	return check2(x, y, cnt);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	pref.resize(n), fi.resize(n), dist.resize(n);
	for (int i = 0; i < n; i++)
		pref[i] = '1' - s[i];
	for (int i = 1; i < n; i++)
		pref[i] += pref[i - 1];
	int tot = 0;
	for (const auto &i : s)
		if (i == '0') tot++;

	if (tot == 0) {
		cin >> q;
		while (q--) {
			cout << "Yes\n";
		}
		return 0;
	}

	m = tot;

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') {
			tot--;
			fi[i] = tot;
			dist[i] = 0;
		}
		else {
			if (i + 1 < n) {
				fi[i] = fi[i + 1];
				dist[i] = 1 ^ dist[i + 1];
			}
			else {
				fi[i] = tot;
				dist[i] = md;
			}
		}
	}

	int lastpos = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (lastpos != -1) {
				arr.push_back((i - lastpos) & 1);
			}
			lastpos = i;
		}
	}
	//if (OO) cout << "ok\n";
	prep();

	cin >> q;
	while (q--) {
		int x, y, cnt;
		cin >> x >> y >> cnt;
		--x, --y;
		int c1 = count(x, x + cnt - 1), c2 = count(y, y + cnt - 1);
		//cout << c1 << " " << c2 << endl;
		if (c1 != c2) {
			cout << "No\n";
			continue;
		}
		if (c1 == 0) {
			cout << "Yes\n";
			continue;
		}
		if (dist[x] != dist[y]) {
			cout << "No\n";
			continue;
		}
		if (query(fi[x], fi[y], c1))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}