#include<bits/stdc++.h>
using namespace std;
int f[400005],n,a[200005];
void solve(){
	cin>>n;
	int s=n;
	for(int i=0;i<=2*n;i++)f[i]=-1;
	f[s]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1)s--;else s++;
		f[s]=i;
	}
	for(int i=n+1;i<=2*n;i++)scanf("%d",&a[i]);
	s=n;int ans=n*2-f[s];
	for(int i=n*2;i>n;i--){
		if(a[i]==1)s++;else s--;
		if(f[s]==-1)continue;
		ans=min(ans,i-f[s]-1);
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}