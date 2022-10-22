#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a[100000], b[100000], pos[100001];
		cin >> n >> m;
		for (int i=0; i<n; ++i) {
			cin >> a[i];
			pos[a[i]] = i; //position of a[i] in the stack (based 0)
		}
		for (int i=0; i<m; ++i)
			cin >> b[i];

		long long ans = m;
		int lowestRemoved = -1;
		for (int i=0; i<m; ++i) {
			if (pos[b[i]] < lowestRemoved)
				continue;
			ans += 2*(pos[b[i]]-i);
			lowestRemoved = pos[b[i]];
		}
		
		cout << ans << '\n';
	}
	return 0;
}