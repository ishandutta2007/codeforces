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
		for (int i=0; i<n; ++i) {
			int k;
			cin >> k;
			string s;
			cin >> s;
			for (char c : s)
				a[i]=(a[i]+(c=='D'?1:9))%10;
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}