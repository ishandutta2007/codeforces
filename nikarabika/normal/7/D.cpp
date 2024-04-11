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

#define hash HASH

const int maxn = 5e6 + 10;
const LL base = 317,
	  Mod = 1e9 + 7;
LL hash[maxn],
   shah[maxn],
   P[maxn];
int dp[maxn];
string s;

void make(LL *h) {
	h[0] = 0;
	for (int i = 0; i < sz(s); i++)
		h[i + 1] = (h[i] * base + s[i]) % Mod;
}

LL get(int st, int en, LL *h) {
	return ((h[en] - h[st] * P[en - st]) % Mod + Mod) % Mod;
}

bool is_pal(int st, int en) {
	return get(st, en + 1, hash) == get(sz(s) - en - 1, sz(s) - st, shah);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	P[0] = 1;
	for (int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % Mod;
	cin >> s;
	make(hash);
	reverse(all(s));
	make(shah);
	int ans = 0;
	for (int i = 1; i <= sz(s); i++)
		if (is_pal(0, i - 1))
			ans += dp[i] = dp[i >> 1] + 1;
	cout << ans << endl;
	return 0;
}