#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

bool b[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=1; i<=100; ++i)
		b[i*i]=1;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bool ok=1;
		for (int i=0; i<n; ++i) {
			int x;
			cin >> x;
			ok&=b[x];
		}
		cout << (ok?"NO":"YES") << "\n";
	}
	return 0;
}