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

int n;
string a, b, ans = "";
bool can[1000000];

void maximize(string &chk) {
	if (ans.size() == 0) {
		ans = chk;
		return;
	}
	if (chk[0] == '0') return;
	for (int i = 0; i < chk.size(); i++) {
		if (chk[i] < ans[i]) return;
		if (chk[i] > ans[i]) {
			ans = chk;
			return;
		}
	}
}

void calc(int i, string &build, vector<int> &cnt, int comp = 1) {
	if (comp) {
		if (i == b.size()) {
			maximize(build);
			return;
		}
		if (cnt[b[i] - '0']) {
			cnt[b[i] - '0']--;
			build.push_back(b[i]);
			calc(i + 1, build, cnt, 1);
			build.pop_back();
			cnt[b[i] - '0']++;
		}
		if (b[i] != '0') {
			int xd = b[i] - '0' - 1;
			for (; xd >= 0 && !cnt[xd]; xd--);
			if (xd >= 0) {
				cnt[xd]--;
				build.push_back(char(xd + '0'));
				calc(i + 1, build, cnt, 0);
				build.pop_back();
				cnt[xd]++;
			}
		}
	}
	else {
		for (int i = 9; i >= 0; i--)
			for (int j = 0; j < cnt[i]; j++)
				build.push_back(char(i + '0'));
		maximize(build);
		while (build.size() > i) build.pop_back();
	}
}

int main() {
	fast;
	cin >> a >> b;
	if (a.size() < b.size()) {
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		finish(a);
	}
	vector<int> cnt(10, 0);
	for (auto &i : a) cnt[i - '0']++;

	string build = "";
	calc(0, build, cnt);
	cout << ans << endl;
}