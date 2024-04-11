#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll md = 1e9 + 7;

ll bpw(ll a, ll b) {
	if (b <= 0)return 1;
	ll tmp = bpw(a, b >> 1);
	tmp *= tmp;
	tmp %= md;
	if (b & 1) {
		tmp *= a;
		tmp %= md;
	}
	return tmp;
}

const int sz = 3e5;
int pre[sz][4], n;
string s;

inline int query(int i, int j, int k) {
	if (i > j)return 0;
	return pre[j][k] - (i ? pre[i - 1][k] : 0);
}

void initPre() {
	for (int i = 0; i < n; i++) {
		if (i) {
			for (int j = 0; j < 4; j++)pre[i][j] = pre[i - 1][j];
		}
		switch (s[i]) {
		case 'a':
			pre[i][0]++;
			break;
		case 'b':
			pre[i][1]++;
			break;
		case 'c':
			pre[i][2]++;
			break;
		case '?':
			pre[i][3]++;
			break;
		}
	}
}

int main() {
	fast;
	cin >> n >> s;
	initPre();
	ll tot = 0;
	ll k = pre[n - 1][3];
	ll tpw[]{ bpw(3,k),bpw(3,k - 1),bpw(3,k - 2),bpw(3,k - 3) };
	for (int i = 0; i < n; i++) {
		if (s[i] == 'b') {
			tot += (tpw[0] * query(0, i - 1, 0)*query(i + 1, n - 1, 2));
			tot %= md;
			tot += (tpw[1] * query(0, i - 1, 3)*query(i + 1, n - 1, 2));
			tot %= md;
			tot += (tpw[1] * query(0, i - 1, 0)*query(i + 1, n - 1, 3));
			tot %= md;
			tot += (tpw[2] * query(0, i - 1, 3)*query(i + 1, n - 1, 3));
			tot %= md;
		}
		else if (s[i] == '?') {
			tot += (tpw[1] * query(0, i - 1, 0)*query(i + 1, n - 1, 2));
			tot %= md;
			tot += (tpw[2] * query(0, i - 1, 3)*query(i + 1, n - 1, 2));
			tot %= md;
			tot += (tpw[2] * query(0, i - 1, 0)*query(i + 1, n - 1, 3));
			tot %= md;
			tot += (tpw[3] * query(0, i - 1, 3)*query(i + 1, n - 1, 3));
			tot %= md;
		}
	}
	cout << tot << endl;
	return 0;
}