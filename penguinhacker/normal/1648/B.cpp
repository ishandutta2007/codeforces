#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, c, p[mxN+1];
bool has[mxN+1];

void solve() {
	cin >> n >> c;
	memset(has, 0, c+1);
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		has[x]=1;
	}
	for (int i=1; i<=c; ++i)
		p[i]=p[i-1]+has[i];
	for (int i=1; i<=c; ++i)
		if (has[i])
			for (int j=i; j<=c; j+=i)
				if (p[min(c, j+i-1)]>p[j-1]&&!has[j/i]) {
					cout << "No\n";
					return;
				}
	cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}