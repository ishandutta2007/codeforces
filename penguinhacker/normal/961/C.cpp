#include <bits/stdc++.h>
using namespace std;

int n, a[4]={0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int x=0; x<4; ++x) {
		for (int i=0; i<n; ++i) {
			string s;
			cin >> s;
			for (int j=0; j<n; ++j) {
				if (s[j] != ('0'+((i+j)&1)))
					a[x]++;
			}
		}
	}
	sort(a, a+4);
	cout << 2*n*n-a[3]-a[2]+a[1]+a[0];
	return 0;
}