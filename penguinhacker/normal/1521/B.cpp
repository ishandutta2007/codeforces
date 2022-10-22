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
		int ind=min_element(a.begin(), a.end())-a.begin();
		cout << n-1 << "\n";
		for (int i=0; i<n; ++i) {
			if (i==ind)
				continue;
			int par=abs(i-ind)%2;
			cout << ind+1 << " " << i+1 << " " << a[ind] << " " << a[ind]+par << "\n";
		}
	}
	return 0;
}