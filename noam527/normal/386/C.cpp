#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s;
vector<ll> a = { 0 }, b;

void work(int k) {
	vector<int> ch(26, 0);
	ch[s[0] - 'a']++;
	int p1 = 0, p2 = 0, c = 1;
	ll tot = 0;

	while (p2 < s.size()) {
		if (c <= k) {
			tot += (p2 - p1 + 1);
			p2++;
			if (p2 < s.size()) {
				if (!ch[s[p2] - 'a']) c++;
				ch[s[p2] - 'a']++;
			}
		}
		else {
			if (ch[s[p1] - 'a'] == 1) c--;
			ch[s[p1] - 'a']--;
			p1++;
		}
	}
	a.push_back(tot);
}

int main() {
	cin >> s;
	for (int i = 1; i <= 26; i++) work(i);
	for (int i = 1; i <= 26; i++) if (a[i] - a[i - 1]) b.push_back(a[i] - a[i - 1]);
	cout << b.size() << endl;
	for (auto &i : b) cout << i << endl;
}