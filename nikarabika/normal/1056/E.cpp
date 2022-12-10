//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

#define hash jsdsdf
#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((LL)(x).size())

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

const int maxn = 1000 * 1000 + 10;
const LL Mod0 = 1e9 + 7,
	  Mod1 = 1e9 + 9,
	  base = 313;
pll hash[maxn],
	P[maxn];
vector<int> poss[2];
string s, t;

pll get(int st, int en) {
	return MP(((hash[en].L - hash[st].L * P[en - st].L) % Mod0 + Mod0) % Mod0, ((hash[en].R - hash[st].R * P[en - st].R) % Mod1 + Mod1) % Mod1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	P[0] = MP(1, 1);
	for (int i = 1; i < maxn; i++)
		P[i] = MP(P[i - 1].L * base % Mod0, P[i - 1].R * base % Mod1);

	cin >> s >> t;
	for (int i = 0; i < sz(t); i++) {
		hash[i + 1] = MP(hash[i].L * base + t[i], hash[i].R * base + t[i]);
		hash[i + 1].L %= Mod0;
		hash[i + 1].R %= Mod1;
	}

	if (s[0] == '1')
		for (auto &c : s)
			c ^= '0' ^ '1';

	int cnt[2] = {0, 0};
	for (int i = 0; i < sz(s); i++) {
		char c = s[i];
		cnt[c - '0']++;
		poss[c - '0'].PB(i);
	}
	
	//cout << get(0, 4).L << ' ' << get(0, 4).R << ' ' << get(4, 8).L << ' ' << get(4, 8).R << endl;
	int ans = 0;
	for (LL l0 = 1; l0 < sz(t); l0++)
		if ((sz(t) - l0 * cnt[0]) % cnt[1] == 0) {
			LL l1 = (sz(t) - l0 * cnt[0]) / cnt[1];
			if (l1 <= 0) continue;
			bool good = true;
			int st0 = 0,
				en0 = l0;
			auto h0 = get(st0, en0);
			int st1 = poss[1][0] * l0;
			int en1 = st1 + l1;
			auto h1 = get(st1, en1);
			if (h0 == h1) continue;
			int pos = 0;	
			for (auto c : s) {
				if (c == '0') {
					good &= (get(pos, pos + l0) == h0);
					pos += l0;
				}
				else {
					good &= (get(pos, pos + l1) == h1);
					pos += l1;
				}
				if (!good) {
					break;
				}
			}
			ans += good;
		}
	cout << ans << endl;
	return 0;
}