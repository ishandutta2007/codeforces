#include<bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	for (int i=0;i<n;i++) {
		int b;
		cin>>b;
		for (int j=0;j<n;j++) {
			cout<<(b+1LL*(j-i+n)%n*i)%n<<" \n"[j+1==n];
		}
	}
	
	return 0;
}