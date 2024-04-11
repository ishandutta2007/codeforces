#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 0;
using namespace std;

int n;
int ans = 0;
int C[100005] = {};
int CC[100005] = {};
set<int> pos;

void add(int x) {
	if (C[x]) {
		CC[C[x]]--;
		if (CC[C[x]] == 0) pos.erase(C[x]);
	}
	C[x]++;
	CC[C[x]]++;
	if (CC[C[x]] == 1) pos.insert(C[x]);
}

bool good() {
	if (pos.size() == 1 && CC[*pos.begin()] == 1) return true;
	if (pos.size() > 2) return false;
	if (CC[*pos.rbegin()] == 1 && *pos.begin() + 1 == *pos.rbegin()) return true;
	if (*pos.begin() == 1 && CC[1] == 1) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		add(x);
		if (CC[1] == i + 1) ans = max(ans, i + 1);
		if (good()) ans = max(ans, i + 1);
	}
	finish(ans);
}