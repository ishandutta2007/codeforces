#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int sz = 5e3 + 5;
pair<pii, int> p[sz];
int n;
vector<int> ret;
bitset<sz> used;

bool ok(const pii& a, const pii& b, const pii& c) {
	pii da = { a.ff - b.ff,a.ss - b.ss }, db = { c.ff - b.ff,c.ss - b.ss };
	return da.ff*db.ff + da.ss*db.ss > 0;
}

int main() {
	fast;
	cin >> n;
	foru(i, 0, n) {
		cin >> p[i].ff.ff >> p[i].ff.ss;
		p[i].ss = i;
	}
	ret.resize(3);
	vector<int> dd{ 0,1,2 };
	do {
		if (ok(p[dd[0]].ff, p[dd[1]].ff, p[dd[2]].ff)) {
			foru(i, 0, 3)ret[i] = p[dd[i]].ss;
			break;
		}
	} while (next_permutation(dd.begin(), dd.end()));
	foru(i, 3, n) {
		bool found = 0;
		foru(j, 0, i - 1) {
			if (ok(p[i].ff, p[ret[j]].ff, p[ret[j + 1]].ff)) {
				ret.insert(ret.begin() + j, i);
				found = 1;
				break;
			}
		}
		if (!found) {
			if (ok(p[ret[i - 2]].ff, p[ret[i - 1]].ff, p[i].ff)) {
				ret.pb(i);
				found = 1;
				break;
			}
		}
		if (!found) {
			cout << -1 << '\n';
			return 0;
		}
	}
	foru(i, 0, n)cout << ret[i] + 1 << ' ';
	cout << '\n';
	return 0;
}