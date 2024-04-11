#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int gcd(int x,int y) {
	return !y?x:gcd(y,x%y);
}
int lcm(int x,int y) {
	return x/gcd(x,y)*y;
}
int n,a[N],b[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	b[1]=a[1];
	b[n+1]=a[n];
	for (int i=2;i<=n;i++) {
		b[i]=lcm(a[i-1],a[i]);
	}
	for (int i=1;i<=n;i++) {
		if (gcd(b[i],b[i+1])!=a[i]) {
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
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