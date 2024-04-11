#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	int ans=0;
	for (int i=0; i<n; ++i) {
		for (int j=i; j<min(n, i+5); ++j) {
			bool ok=1;
			for (int x=i; x<=j; ++x)
				for (int y=x+1; y<=j; ++y)
					for (int z=y+1; z<=j; ++z)
						if (a[x]<=a[y]&&a[y]<=a[z]||a[x]>=a[y]&&a[y]>=a[z])
							ok=0;//, cout << x << " " << y << " " << z << endl;
			//cout << i << " " << j << " " << ok << endl;
			ans+=ok;
		}
	}
	cout << ans << "\n";
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