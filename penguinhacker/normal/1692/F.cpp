#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	vector<int> cnt(10);
	int n;
	cin >> n;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		++cnt[x%10];
	}
	for (int i=0; i<10; ++i)
		for (int j=i; j<10; ++j)
			for (int k=i; k<10; ++k) {
				if ((i+j+k)%10!=3)
					continue;
				--cnt[i], --cnt[j], --cnt[k];
				if (cnt[i]>=0&&cnt[j]>=0&&cnt[k]>=0) {
					cout << "YES\n";
					return;
				}
				++cnt[i], ++cnt[j], ++cnt[k];
			}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}