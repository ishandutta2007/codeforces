#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, A, B, C, T, t;
int main(){
	cin>>n>>A>>B>>C>>T;
	ll ans=0;
	for(int i=0; i<n; i++){
		cin>>t;
		int diff=T-t;
		if(B-C>0) ans+=A;
		else ans+=A+(C-B)*diff;
	}
	cout<<ans<<endl;
	return 0;
}