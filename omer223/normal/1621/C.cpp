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
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

int totQ = 0;

int ask(int pos) {
	cout << "? " << pos << endl;
	fflush(stdout);
	int ans;
	cin >> ans;
	totQ++;
	return ans;
}

void solve() {
	int n;
	totQ = 0;
	cin >> n;
	vector<bool> seen(n + 1, 0);
	vector<int> curCyc;
	vector<int> p(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!seen[i]) {
			int ans = i, askbefore = totQ;
			while (1) {
				ans = ask(i);
				if (seen[ans])break;
				else {
					seen[ans] = 1;
					curCyc.push_back(ans);
				}
			}
			int cycSz = curCyc.size();
			int idx = -1;
			for (int j = 0; j < cycSz; j++) {
				if (curCyc[j] == i) {
					idx = j;
					break;
				}
			}
			for (int j = 0; j < cycSz; j++) {
				seen[curCyc[j]] = 1;
				p[curCyc[(j + idx) % cycSz]] = curCyc[(j + idx + 1) % cycSz];
			}
			curCyc.clear();
		}
	}
	cout << "! ";
	for (int i = 1; i <= n; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
	fflush(stdout);
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}