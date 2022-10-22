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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		for (int i=0; i<n-1; ++i) {
			if (k<=a[i]) {
				a[i]-=k, a[n-1]+=k;
				break;
			}
			k-=a[i], a[n-1]+=a[i], a[i]=0;
		}
		for (int i=0; i<n; ++i)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}