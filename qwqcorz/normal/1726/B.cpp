#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
void work() {
	cin>>n>>m;
	int k=n-1;
	if (k&1) {
		k--;
	}
	int p=n-k;
	if (m<n||(m-n)%p) {
		cout<<"No\n";
		return;
	}
	m-=k;
	cout<<"Yes\n";
	while (k--) {
		cout<<"1 ";
	}
	for (int i=1;i<=p;i++) {
		cout<<m/p<<" \n"[i==p];
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