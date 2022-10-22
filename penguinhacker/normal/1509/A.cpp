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
		sort(a.begin(), a.end(), [](int x, int y) {return x%2<y%2;});
		for (int i : a)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}