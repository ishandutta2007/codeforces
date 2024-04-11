#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <string>
#include <queue>
#include <time.h>
#include <chrono>
#include <random>
#include <iomanip>
#include <map>
#include <numeric>
#include <complex>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, pair<pii, int>> einf;

vector<pii> tres;
vector<pii> locs;
set<pii> digAlready;
int n, m;

int qudig(pii qu) {
	return (qu == tres[0] || qu == tres[1]);
}

int quans(pii qu) {
	int sm = 0;
	for (auto ii : tres)sm += abs(ii.ff - qu.ff) + abs(ii.ss - qu.ss);
	return sm;
}

int ask(pii qu) {
	cout << "SCAN " << qu.ff+1 << ' ' << qu.ss+1 << endl;
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

bool dig(pii ii) {
	if (digAlready.count(ii))return 0;
	cout << "DIG " << ii.ff + 1 << ' ' << ii.ss + 1 << endl;
	fflush(stdout);
	int ans;
	cin >> ans;
	digAlready.insert(ii);
	return ans;
}

void solve() {
	tres.clear();
	locs.clear();
	digAlready.clear();
	cin >> n >> m;
	foru(i, 0, n) {
		foru(j, 0, m)locs.push_back({ i,j });
	}
	int k = locs.size();
	vector<vector<pii>> popts;
	foru(i, 0, k) {
		foru(j, i + 1, k)popts.push_back(vector<pii>{locs[i], locs[j]});
	}
	int truAns = ask(locs[0]);
	vector<vector<pii>> npopts;
	for (auto ii : popts) {
		tres = ii;
		if (truAns == quans(locs[0]))
			npopts.push_back(ii);
	}
	popts = npopts;
	while (popts.size() > 2) {
		int bstMax = 100000, idx = -1;
		foru(i, 0, k) {
			vector<int> anscount(2 * (n + m), 0);
			for (auto ii : popts) {
				tres = ii;
				anscount[quans(locs[i])]++;
			}
			int curmax = 0;
			for (int y : anscount)curmax = max(curmax, y);
			if (curmax < bstMax) {
				bstMax = curmax;
				idx = i;
			}
		}
		//cout << "split " << bstMax << '\n';
		int truAns = ask(locs[idx]);
		vector<vector<pii>> npopts;
		for (auto ii : popts) {
			tres = ii;
			if (truAns == quans(locs[idx]))
				npopts.push_back(ii);
		}
		popts = npopts;
	}
	if (popts.size() == 1) {
		vector<pii> ans = *popts.begin();
		dig(ans[0]);
		dig(ans[1]);
		return;
	}
	else {
		vector<pii> ans = *popts.begin();
		vector<pii> rans = *popts.rbegin();
		if (ans[0]!=rans[0]&&ans[0]!=rans[1]) {
			if (dig(ans[0])) {
				dig(ans[1]);
				return;
			}
			else {
				dig(rans[0]);
				dig(rans[1]);
			}
		}
		else {
			if (dig(ans[1])) {
				dig(ans[0]);
				return;
			}
			else {
				dig(rans[0]);
				dig(rans[1]);
			}
		}
	}
}

int foorec(vector<vector<pii>> popts, int k) {
	if (popts.size() <= 2) {
		if (popts.size() == 2)return 3;
		else return 2;
	}
	else {
		int bstMax = 100000, idx = -1;
		foru(i, 0, k) {
			vector<vector<vector<pii>>> anscount(2 * (n + m));
			for (auto ii : popts) {
				tres = ii;
				anscount[quans(locs[i])].push_back(ii);
			}
			int curmax = 0;
			for (auto y : anscount)curmax = max(curmax, (int)y.size());
			if (curmax < bstMax) {
				bstMax = curmax;
				idx = i;
			}
		}
		vector<vector<vector<pii>>> anscount(2 * (n + m));
		for (auto ii : popts) {
			tres = ii;
			anscount[quans(locs[idx])].push_back(ii);
		}
		int dep = 0;
		for (auto vec : anscount) {
			if (vec.size() != 0)dep = max(dep, 1+foorec(vec, k));
		}
		return dep;
	}
}

int main() {
	fast;
	fast;
	int te; cin >> te;
	while (te--)solve();
	
	return 0;
}