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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		int s=0;
		for (int& i : a)
			cin >> i, s+=i;
		cout << max(0, s-m) << "\n";
	}
	return 0;
}