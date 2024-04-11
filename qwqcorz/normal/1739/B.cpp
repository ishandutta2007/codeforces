#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;

int n,a[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=2;i<=n;i++) {
		if (a[i]&&a[i]<=a[i-1]) {
			cout<<"-1\n";
			return;
		}
		a[i]+=a[i-1];
	}
	for (int i=1;i<=n;i++) {
		cout<<a[i]<<" \n"[i==n];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}