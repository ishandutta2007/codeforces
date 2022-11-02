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
#include <stack>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string a, b, c;
int cnt[26], cntb[26], cntc[26];

int main() {
	fast;
	cin >> a >> b >> c;
	for (char cc : a)cnt[cc - 'a']++;
	for (char cc : b)cntb[cc - 'a']++;
	for (char cc : c)cntc[cc - 'a']++;
	int bst = 0, bstb = 0, bstc = 1e9;
	for (int i = 0; i < 26; i++) {
		if (cntc[i]) bstc = min(bstc, cnt[i] / cntc[i]);
	}
	bst = bstc;
	bool done = 0;
	for (int i = 1; i * b.length() <= a.length(); i++) {
		for (int i = 0; i < 26; i++) {
			cnt[i] -= cntb[i];
			if (cnt[i] < 0) {
				done = 1;
				break;
			}
		}
		if (done)break;
		int crc = 1e9;
		for (int i = 0; i < 26; i++) {
			if (cntc[i]) crc = min(crc, cnt[i] / cntc[i]);
		}
		if (bst < i + crc) {
			bst = i + crc;
			bstb = i;
			bstc = crc;
		}
	}
	for (int i = 0; i < 26; i++)cnt[i] = 0;
	for (char cc : a)cnt[cc - 'a']++;
	string res = "";
	for (int i = 0; i < bstb; i++) {
		res += b;
		for (char cc : b)cnt[cc - 'a']--;
	}
	for (int i = 0; i < bstc; i++) {
		res += c;
		for (char cc : c)cnt[cc - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		while (cnt[i]--)res += ('a' + i);
	}
	cout << res << endl;
	return 0;
}