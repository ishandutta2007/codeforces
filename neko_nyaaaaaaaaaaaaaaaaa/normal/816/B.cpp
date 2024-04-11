#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[200003];
signed main() {
	
	int n,k,q;
	cin >> n >> k >> q;
	for(int i = 0; i < n; ++i) {
		int l,r; cin >> l >> r; a[l]++; a[r + 1]--;
	}
	for(int i = 1; i <= 200000; ++i) {
		a[i] += a[i - 1];
	}
	for(int i = 1; i <= 200000; ++i) {
		if(a[i] >= k) a[i] = 1;
		else a[i] = 0;
		a[i] += a[i - 1];
	}
	while(q--) {
		int d,b;
		cin >> d >> b;
		cout << a[b] - a[d-1];
		cout << "\n";
	}
}