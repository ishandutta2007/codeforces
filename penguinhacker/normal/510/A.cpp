#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		if (i%2==0)
			cout << string(m, '#') << "\n";
		else {
			string a(m, '.');
			a[i%4==1?m-1:0]='#';
			cout << a << "\n";
		}
	}
	return 0;
}