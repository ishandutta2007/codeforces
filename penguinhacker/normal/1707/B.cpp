#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		reverse(a.begin(), a.end());
		int cnt0=0;
		auto Norm=[&]() {
			while(a.size()&&a.back()==0) {
				a.pop_back();
				++cnt0;
			}
		};
		Norm();
		for (int i=0; i<n-1; ++i) {
			vector<int> b;
			for (int i=0; i+1<a.size(); ++i)
				b.push_back(a[i]-a[i+1]);
			if (cnt0&&a.size()) {
				b.push_back(a.back());
				--cnt0;
			}
			swap(a, b);
			sort(a.rbegin(), a.rend());
			Norm();
		}
		cout << (a.size()?a[0]:0) << "\n";
	}
	return 0;
}