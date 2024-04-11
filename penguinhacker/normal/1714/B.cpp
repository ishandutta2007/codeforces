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
		set<int> s;
		int ans=n;
		for (int i : a) {
			if (s.find(i)!=s.end()) {
				break;
			}
			s.insert(i);
			--ans;
		}
		cout << ans << "\n";
	}
	return 0;
}