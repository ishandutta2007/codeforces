#include <bits/stdc++.h> 
using namespace std;

#define ll long long

const int mxN=1e6;
int n, a[mxN], b[mxN], a2[mxN];
 
void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], a2[i]=a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	int last=0, mx[2]={};
	for (int i=0; i<n-1; ++i) {
		a2[i+1]=max(0, a2[i+1]-(b[i]-last));
		last=min(a2[i+1], b[i+1]);
		a2[i+1]-=last;
		if (a2[i+1])
			mx[(i+1)%2]=max(mx[(i+1)%2], a2[i+1]);
	}
	if (a2[0]>b[n-1]-last)
		mx[0]=max(mx[0], a2[0]-(b[n-1]-last));
	//cout << mx[0] << " " << mx[1] << "\n";
	if (mx[1]||mx[0]>b[0]) {
		cout << "NO\n";
		return;
	}
	memcpy(a2, a, 4*n);
	last=mx[0], a2[0]-=last;
	for (int i=0; i<n-1; ++i) {
		//cout << last << "\n";
		a2[i+1]=max(0, a2[i+1]-(b[i]-last));
		last=min(a2[i+1], b[i+1]);
		a2[i+1]-=last;
		if (a2[i+1]) {
			cout << "NO\n";
			return;
		}
	}
	//cout << last << "\n";
	a2[0]-=b[n-1]-last;
	//cout << a2[0] << "\n";
	cout << (a2[0]<=0?"YES":"NO") << "\n";
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