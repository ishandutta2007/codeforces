#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 10000001;
bool p[mxN];
vector<int> primes;
int n, k, a[200000];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j : primes) {
			if (j * j > a[i])
				break;
			while(a[i] % (j * j) == 0)
				a[i] /= j * j;
		}
	}
	int ans = 1;
	set<int> oc;
	for (int i = 0; i < n; ++i) {
		if (oc.find(a[i]) != oc.end()) {
			oc.clear();
			++ans;
		}
		oc.insert(a[i]);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(p, 1, sizeof(p));
	for (int i = 2; i < mxN; ++i) {
		if (p[i]) {
			if ((ll)i * i < mxN)
				for (int j = i * i; j < mxN; j += i)
					p[j] = 0;
			primes.push_back(i);
		}
	}
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}