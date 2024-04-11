#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n) {
	ll k=sqrt(n);
	while (k*k>n) {
		k--;
	}
	while ((k+1)*(k+1)<=n) {
		k++;
	}
	return (k-1)*3+(k*k<=n)+(k*(k+1)<=n)+(k*(k+2)<=n);
}
void work() {
	ll l,r;
	cin>>l>>r;
	cout<<solve(r)-solve(l-1)<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while (T--) {
		work();
	} 
	
	return 0;
}