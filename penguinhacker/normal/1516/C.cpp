#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int g=0;
	for (int i=0; i<n; ++i)
		cin >> a[i], g=__gcd(g, a[i]);
	assert(g);
	for (int i=0; i<n; ++i)
		a[i]/=g;
	int s=accumulate(a, a+n, 0);
	bitset<200001> bs;
	if (s%2==0) {
		bs[0]=1;
		for (int i=0; i<n; ++i)
			bs|=bs<<a[i];
	}
	if (s%2||!bs[s/2]) {
		cout << 0;
	} else {
		int ans=-1;
		for (int i=0; i<n; ++i)
			if (a[i]%2)
				ans=i+1;
		assert(ans!=-1);
		cout << "1\n" << ans;
	}
	return 0;
}