#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 149;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s;
vector<pair<int, int>> a;

bool issuf(string &t1, string t2) {
	if (t2.size() > t1.size()) return false;
	for (int i = t1.size() - 1, j = t2.size() - 1; j >= 0; j--, i--)
		if (t1[i] != t2[j]) return false;
	return true;
}

pair<int, int> check(string &t) {
	if (issuf(t, "lios")) return{ 0, 0 };
	if (issuf(t, "liala")) return{ 0, 1 };
	if (issuf(t, "etr")) return{ 1, 0 };
	if (issuf(t, "etra")) return{ 1, 1 };
	if (issuf(t, "initis")) return{ 2, 0 };
	if (issuf(t, "inites")) return{ 2, 1 };
	return{ -1, -1 };
}

int main() {
	fast;
	getline(cin, s);
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') temp.push_back(s[i]);
		else a.push_back(check(temp)), temp = "";
	}
	if (temp != "") a.push_back(check(temp));

	if (a.size() == 1 && a[0].first != -1) return cout << "YES" << endl, 0;

	for (auto &i : a) if (i.first == -1) return cout << "NO" << endl, 0;
	for (int i = 1; i < a.size(); i++) if (a[i].second != a[0].second) return cout << "NO" << endl, 0;
	int p1 = 0, p2 = a.size() - 1;
	while (p1 < a.size() && a[p1].first == 0) p1++;
	while (p2 >= 0 && a[p2].first == 2) p2--;
	if (p1 == a.size() || p2 == -1 || a[p1].first != 1 || a[p2].first != 1 || p1 != p2) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
}