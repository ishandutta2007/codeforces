#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
void test_case() {
	cin >> n;
	vector<int> a(n), b(n);
	vector<bool> taken(n, 0);
	for (int& i : a) cin >> i;
	sort(a.rbegin(), a.rend());
	b[0]=a[0];
	taken[0]=1;
	int cur=a[0];
	//cout << cur << "\n";
	for (int i=1; i<n; ++i) {
		int nxt=-1;
		for (int j=0; j<n; ++j) {
			if (taken[j]) {
				continue;
			}
			if (nxt==-1||__gcd(cur, a[j])>__gcd(cur, a[nxt])) nxt=j;
		}
		assert(nxt!=-1);
		cur=__gcd(cur, a[nxt]);
		b[i]=a[nxt];
		taken[nxt]=1;
		//cout << cur << "\n";
	}
	for (int i : b) cout << i << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		test_case();
	}
	return 0;
}