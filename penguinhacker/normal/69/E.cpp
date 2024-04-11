#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[100000], cnt[100000];
multiset<int> s;

void op(int i, int val) {
	if (cnt[a[i]]==1)
		s.erase(s.find(a[i]));
	cnt[a[i]]+=val;
	if (cnt[a[i]]==1)
		s.insert(a[i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	vector<int> d(a, a+n);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	for (int i=0; i<n; ++i)
		a[i]=lower_bound(d.begin(), d.end(), a[i])-d.begin();
	for (int i=0; i<n; ++i) {
		op(i, 1);
		if (i-k>=0) {
			op(i-k, -1);
		}
		if (i>=k-1) {
			if (s.empty()) {
				cout << "Nothing\n";
			}
			else {
				cout << d[*s.rbegin()] << "\n";
			}
		}
	}
	return 0;
}