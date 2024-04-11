#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int n,p[N],a[N],b[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>p[i];
		a[i]=p[i]-p[i-1];
		b[i]=i;
	}
	sort(b+1,b+1+n,[&](int x,int y) {
		return a[x]>a[y];
	});
	for (int i=1;i<=n;i++) {
		cout<<b[i]<<" \n"[i==n];
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