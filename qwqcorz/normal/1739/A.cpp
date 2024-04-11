#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
void work() {
	cin>>n>>m;
	cout<<(n+1)/2<<' '<<(m+1)/2<<"\n";
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