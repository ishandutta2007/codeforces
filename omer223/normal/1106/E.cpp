#define _CRT_SECURE_NO_WARNINGS
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
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> qua;

const int sz = 1e5 + 2, szM = 201;
int n, m, k;
qua ev[sz];
ll dp[sz], prv[sz];
int bst[sz];
vector<pair<int, pii>> segs;

void input() {
	cin >> n >> m >> k;
	foru(i, 0, k) {
		cin >> ev[i].first.first >> ev[i].first.second >> ev[i].second.first >> ev[i].second.second;
		segs.pb({ ev[i].first.first,{1,i} });
		segs.pb({ ev[i].first.second + 1,{0,i} });
	}
}

void sweepline() {
	sort(segs.begin(), segs.end());
	int t = 1, ind = 0, segSz = segs.size();
	set<pair<pii, int>, greater<pair<pii, int>>> s;
	while (t <= n) {
		while (ind < segSz&&segs[ind].first == t) {
			int myind = segs[ind].second.second;
			if (segs[ind].second.first == 1)s.insert({ {ev[myind].second.second,ev[myind].second.first},myind });
			else s.erase({ {ev[myind].second.second,ev[myind].second.first},myind });
			ind++;
		}
		if (!s.empty())bst[t] = s.begin()->second;
		else bst[t] = -1;
		t++;
	}
}

void init() {
	for (int j = 0; j <= n; j++) {
		dp[j] = 1e15; prv[j] = 1e15;
	}
}

int main() {
	fast;
	input();
	sweepline();
	init();
	for (int j = n; j >= 1; j--) {
		if (bst[j] == -1)prv[j] = prv[j + 1];
		else prv[j] = ev[bst[j]].second.second + prv[ev[bst[j]].second.first + 1];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= 1; j--) {
			if (bst[j] == -1)dp[j] = dp[j + 1];
			else dp[j] = min(ev[bst[j]].second.second + dp[ev[bst[j]].second.first + 1], prv[j + 1]);
		}
		for (int j = n; j >= 1; j--)prv[j] = dp[j];
	}
	cout << prv[1] << '\n';
	return 0;
}