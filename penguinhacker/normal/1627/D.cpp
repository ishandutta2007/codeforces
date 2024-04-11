#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, a[mxN];
bool b[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		b[a[i]]=1;
	}
	int ans=0;
	for (int i=mxN/2; i; --i) {
		if (b[i])
			continue;
		int g=0;
		for (int j=2*i; j<=mxN; j+=i)
			if (b[j])
				g=g?__gcd(g, j):j;
		if (g==i)
			b[i]=1, ++ans;
	}
	cout << ans;
	return 0;
}