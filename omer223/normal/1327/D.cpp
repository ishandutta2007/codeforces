#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <bitset>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5;
int n;
int p[sz], c[sz];
bitset<sz> bs;

void input() {
	cin >> n;
	foru(i, 0, n) {
		cin >> p[i]; p[i]--;
	}
	foru(i, 0, n)cin >> c[i];
}

void reset() {
	foru(i, 0, n)bs[i] = 0;
}

vector<int> getDivisors(int num) {
	vector<int> ans;
	for (int i = 1; i * i <= num; i++) {
		if (num%i == 0) {
			ans.pb(i);
			if (i*i != num)ans.pb(num / i);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int foo(vector<int> colseq) {
	int len = colseq.size(), quotient;
	vector<int> divs = getDivisors(len);
	for (int d : divs) {
		quotient = len / d;
		for (int rem = 0; rem < d; rem++) {
			bool bad = 0;
			for (int i = 1; i < quotient; i++) {
				if (colseq[i*d + rem] != colseq[(i - 1)*d + rem]) {
					bad = 1;
					break;
				}
			}
			if (!bad)return d;
		}
	}
	return len;
}

void solve() {
	input();
	int ans = n;
	int ind = 0;
	vector<int> col;
	while (ind < n) {
		if (!bs[ind]) {
			while (!bs[ind]) {
				bs[ind] = 1;
				col.pb(c[ind]);
				ind = p[ind];
			}
			ans = min(ans, foo(col));
			col.clear();
		}
		ind++;
	}
	cout << ans << endl;
	reset();
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}