#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:66777216")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
#include <cstring>
#include <unordered_map>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fornn(i, q, n) for (int i = q; i < (ll)n; i++)
#define mp make_pair
#define pk push_back
#define all(v) v.begin(), v.end()
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define prev pprev

#define TASK "elections"

const double EPS = 1e-7;
const double PI = acos(-1.0);

const ll INF = (ll)2e9 + 1;
const ll LINF = (ll)8e18;
const ll MM = (ll)1e9 + 7;

int solve();
void gen();

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
	//freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("test.txt", "w", stderr);
#endif
	solve();
	return 0;
}

const int MAXN = 1e5 + 7;
const int MAXC = 5e7;



int solve() {
	int n;
	string s1, s2;
	scanf("%d\n", &n);
	vector<int> G(n), H(n);
	forn(i, n) {
		scanf("%d", &G[i]);
	}
	forn(i, n) {
		scanf("%d", &H[i]);
	}
	vector<int> cur1, cur2;
	bool ok = false;
	forn(i, n) {
		if (ok) {
			cur2.push_back(G[i]);
		}
		else {
			if (G[i] == 0) {
				ok = true;
			}
			else {
				cur1.push_back(G[i]);
			}
		}
	}
	vector<int> T = cur2;
	forn(i, cur1.size()) {
		T.push_back(cur1[i]);
	}
	cur1.resize(0);
	cur2.resize(0);
	ok = false;
	forn(i, n) {
		if (ok) {
			cur2.push_back(H[i]);
		}
		else {
			if (H[i] == 0) {
				ok = true;
			}
			else {
				cur1.push_back(H[i]);
			}
		}
	}
	vector<int> W = cur2;
	forn(i, cur1.size()) {
		W.push_back(cur1[i]);
	}
	cur1.resize(0);
	cur2.resize(0);
	ok = false;
	forn(i, W.size()) {
		if (ok) {
			cur2.push_back(W[i]);
		}
		else {
			if (W[i] == T[0]) {
				ok = true;
				cur2.push_back(W[i]);
			}
			else {
				cur1.push_back(W[i]);
			}
		}
	}
	forn(i, cur1.size()) {
		cur2.push_back(cur1[i]);
	}

	cur2 == T ? cout << "Yes" : cout << "No";
	return 0;
}