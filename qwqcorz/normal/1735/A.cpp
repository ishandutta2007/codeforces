#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void work() {
	cin>>n;
	cout<<((n-6)/3)<<"\n";
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