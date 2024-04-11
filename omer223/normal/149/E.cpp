#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6;
int textLen, n;
string text, s;
int pi[sz], z[sz], mxs[sz];

void zalg() {
	for (int i = 0; i < n; i++)z[i] = 0;
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
}

void kmp() {
	for (int i = 0; i < n; i++)pi[i] = 0;
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
}

bool solve() {
	string pat;
	cin >> pat;
	if (pat.length() < 2)return false;
	s = pat + "#" + text;
	n = s.length();
	zalg();
	reverse(pat.begin(), pat.end());
	reverse(text.begin(), text.end());
	s = pat + '#' + text;
	kmp();
	reverse(text.begin(), text.end());
	reverse(pi + pat.size() + 1, pi + s.size());
	foru(i, 0, textLen) {
		pi[i] = pi[i + pat.length() + 1];
		z[i] = z[i + pat.length() + 1];
	}
	mxs[textLen - 1] = pi[textLen - 1];
	ford(i, textLen - 2, 0) mxs[i] = max(mxs[i + 1], pi[i]);
	foru(i, 0, textLen) {
		if (z[i] == pat.length())return true;
		if (z[i] == 0)continue;
		int dif = pat.length() - z[i], nxt = i + z[i] + 1;
		if (dif <= mxs[nxt])return true;
	}
	return false;
}

int main() {
	fast;
	cin >> text;
	textLen = text.length();
	int q, tot = 0;
	cin >> q;
	while (q--)
		tot+=solve();
	cout << tot << '\n';
	return 0;
}