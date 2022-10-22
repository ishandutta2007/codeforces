#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, a[mxN], nxt1[mxN], nxt2[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	nxt1[n-1]=nxt2[n-1]=n-1;
	for (int i=n-2; ~i; --i) {
		nxt1[i]=a[i]<=a[i+1]?nxt1[i+1]:i;
		nxt2[i]=a[i]>=a[i+1]?nxt2[i+1]:i;
	}
	while(m--) {
		int l, r;
		cin >> l >> r, --l, --r;
		cout << (nxt1[l]>=r||nxt2[nxt1[l]]>=r?"Yes":"No") << "\n";
	}
	return 0;
}