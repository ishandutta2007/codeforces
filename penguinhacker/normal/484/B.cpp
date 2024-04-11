#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MX=1e6;
int n, a[MX], p[MX+1], prv[MX+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], ++p[a[i]];
	prv[0]=-1;
	for (int i=1; i<=MX; ++i)
		prv[i]=p[i]?i:prv[i-1];
	for (int i=1; i<=MX; ++i)
		p[i]+=p[i-1];
	int ans=0;
	for (int i=2; i<=MX; ++i) {
		if (p[i]==p[i-1])
			continue;
		for (int j=i; j<MX; j+=i)
			ans=max(ans, prv[min(MX, i+j-1)]-j);
	}
	cout << ans;
	return 0;
}