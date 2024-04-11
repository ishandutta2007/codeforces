#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

int s[N];
void work() {
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=k;i++) {
		cin>>s[i];
	}
	for (int i=k;i>=2;i--) {
		s[i]-=s[i-1];
	}
	for (int i=3;i<=k;i++) {
		if (s[i-1]>s[i]) {
			cout<<"NO\n";
			return;
		}
	}
	if (k==1) {
		cout<<"YES\n";
		return;
	}
	if (1LL*s[2]*(n-k+1)>=s[1]) {
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
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