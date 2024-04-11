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
		sort(a.begin(), a.end());
		int s=-1;
		for (int i=0; i+1<n; ++i)
			if (s==-1||a[i+1]-a[i]<a[s+1]-a[s])
				s=i;
		cout << a[s] << " ";
		for (int i=s+2; i<n; ++i)
			cout << a[i] << " ";
		for (int i=0; i<s; ++i)
			cout << a[i] << " ";
		cout << a[s+1] << "\n";
	}
	return 0;
}