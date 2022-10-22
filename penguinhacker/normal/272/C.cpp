#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

ll n, m, curr=0, a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	cin >> m;
	while (m--) {
		int w, h;
		cin >> w >> h, w--;
		cout << max(curr, a[w]) << '\n';
		curr=max(curr, a[w])+h;
	}
	return 0;
}