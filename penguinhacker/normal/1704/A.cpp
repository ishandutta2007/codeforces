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
		string a, b;
		cin >> n >> m >> a >> b;
		if (a.substr(n-m+1)!=b.substr(1)) {
			cout << "NO\n";
			continue;
		}
		cout << (find(a.begin(), a.begin()+n-m+1, b[0])!=a.begin()+n-m+1?"YES":"NO") << "\n";
	}
	return 0;
}