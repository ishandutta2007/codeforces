#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MX=1e7;

int n, p[MX+1], a[500000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i=2; i<=MX; ++i) {
		if (p[i]!=0) continue;
		if (i*i>MX) break;
		for (int j=i*i; j<=MX; j+=i)
			p[j]=i;
	}
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i) {
		if (p[a[i]]==0) {
			cout << -1 << ' ';
			continue;
		}
		int x=a[i];
		while (x%p[a[i]]==0)
			x/=p[a[i]];
		cout << (x==1?-1:a[i]/x) << ' ';
	}
	cout << '\n';
	for (int i=0; i<n; ++i) {
		if (p[a[i]]==0) {
			cout << -1 << ' ';
			continue;
		}
		int x=a[i];
		while(x%p[a[i]]==0)
			x/=p[a[i]];
		cout << (x==1?-1:x) << ' ';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/