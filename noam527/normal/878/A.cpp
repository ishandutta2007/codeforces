#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, x;
char c;
vector<pair<char, int>> ans;
vector<int> b(10, 2), inb(10);

void br() {
	for (int i = 0, j = 1; i < 10; i++, j <<= 1)
		inb[i] = (x & j ? 1 : 0);
}

bool door() {
	bool rtn = false;
	for (int i = 0; i < 10; i++)
		if (inb[i]) {
			if (b[i] != 1) b[i] = 1, rtn = true;
		}
	return rtn;
}

bool doand() {
	bool rtn = false;
	for (int i = 0; i < 10; i++)
		if (!inb[i]) {
			if (b[i] != 0) b[i] = 0, rtn = true;
		}
	return rtn;
}

bool doxor() {
	bool rtn = false;
	for (int i = 0; i < 10; i++) {
		if (inb[i]) {
			rtn = true;
			if (b[i] < 2) b[i] ^= 1;
			else b[i] = 5 - b[i];
		}
	}
	return rtn;
}

int main() {
	fast;
//	for (int i = 0; i < 1024; i++)
//		if ((((i | 3) ^ 2) | 1) != (i & 1021)) finish(i);
	cin >> n;
	while (n--) {
		cin >> c >> x;
		br();
		bool temp;
		if (c == '|') temp = door();
		if (c == '&') temp = doand();
		if (c == '^') temp = doxor();
//		for (auto &i : b) cout << i << " "; cout << endl;
	}

	int l[4] = { 0,0,0,0 };
	for (int i = 0; i < 10; i++)
		l[b[i]] += (1 << i);

//	for (auto &i : b) cout << i << " "; cout << endl;

	ans.push_back({ '&', l[1] + l[2] + l[3] });
	ans.push_back({ '|', l[1] });
	ans.push_back({ '^', l[3] });
	cout << ans.size() << endl;
	for (auto &i : ans) cout << i.first << " " << i.second << endl;
}