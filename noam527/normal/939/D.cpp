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
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
string s, t;

int p[26];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}
bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		p[x] = y;
		return true;
	}
	return false;
}

vector<pair<char, char>> ans;

int main() {
	fast;
	for (int i = 0; i < 26; i++) p[i] = i;
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++)
		if (s[i] != t[i] && merge(s[i] - 'a', t[i] - 'a')) ans.push_back({ s[i], t[i] });
	cout << ans.size() << endl;
	for (const auto &i : ans) cout << i.first << " " << i.second << endl;
}