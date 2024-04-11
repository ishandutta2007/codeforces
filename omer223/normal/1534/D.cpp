#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

set<pii> e;
int n;

vector<int> ask(int x) {
	cout << "? " << x << endl;
	fflush(stdout);
	vector<int> ans(n);
	foru(i, 0, n)cin >> ans[i];
	return ans;
}

int main() {
	fast;
	cin >> n;
	fflush(stdout);
	int cur = 1;
	vector<int> v = ask(cur);
	int od = 0, ev = 0;
	foru(i, 0, n) {
		if (v[i] == 1)e.insert({ min(i + 1,cur),max(i + 1,cur) });
		if (v[i] & 1)od++;
		else ev++;
	}
	ev--;
	if (od > ev) {
		vector<int> u;
		foru(cur, 0, n) {
			if (!(v[cur] & 1) && cur != 0) {
				u = ask(cur + 1);
				foru(i, 0, n) {
					if (u[i] == 1)e.insert({ min(i + 1,cur + 1),max(i + 1,cur + 1) });
				}
			}
		}
	}
	else {
		vector<int> u;
		foru(cur, 0, n) {
			if ((v[cur] & 1)) {
				u = ask(cur + 1);
				foru(i, 0, n) {
					if (u[i] == 1)e.insert({ min(i + 1,cur + 1),max(i + 1,cur + 1) });
				}
			}
		}
	}
	cout << "!" << endl;
	for (pii ii : e)cout << ii.ff << ' ' << ii.ss << '\n';
	return 0;
}