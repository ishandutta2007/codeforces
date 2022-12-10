//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e6 + 10;
const LL Mod = 1e9 + 7,
	  base = 313;
LL P[maxn];
int n;

class HashedString {
	public:
	string s;
	vector<LL> hsh;

	void init() {
		hsh.PB(0);
		for (auto c : s)
			hsh.PB((hsh.back() * base + c) % Mod);
	}

	void operator += (const HashedString &nxt) {
		for (int i = min(sz(s), sz(nxt.s)); i >= 0; --i) {
			if (nxt.hsh[i] == get_hash(sz(s) - i, sz(s))) {
				s += nxt.s.substr(i, sz(nxt.s) - i);
				for (int j = sz(hsh) - 1; j < sz(s); j++)
					hsh.PB((hsh.back() * base + s[j]) % Mod);
				break;
			}
		}
	}

	LL get_hash(int st, int en) {
		return ((hsh[en] - hsh[st] * P[en - st]) % Mod + Mod) % Mod;
	}

} result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	result.hsh.PB(0);
	P[0] = 1;
	for (int i = 1; i < maxn; i++)
		P[i] = P[i - 1] * base % Mod;
	cin >> n;
	for (int i = 0; i < n; i++) {
		HashedString str;
		cin >> str.s;
		str.init();
		result += str;
	}
	cout << result.s << '\n';
	return 0;
}