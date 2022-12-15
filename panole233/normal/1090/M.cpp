#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k,a[N],i,ans,s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=a[i-1])++s;
			else ans=max(ans,s),s=1;
	}
	ans=max(ans,s);
	cout<<ans<<'\n';
	return 0;
}