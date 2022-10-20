#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n; 
void work() {
	string s;
	cin>>n>>s;
	int ans=n+1;
	for (int i=0;i+1<n*2;i++) {
		ans-=s[i]=='('&&s[i+1]==')';
	}
	cout<<ans<<"\n";
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