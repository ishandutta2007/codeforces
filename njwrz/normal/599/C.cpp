#include <bits/stdc++.h>
using namespace std;
int mini[100005],maxi[100005];
int main(){
	int n,a[100005];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0,m=0;mini[n+1]=1000000000;
	for(int i=n;i>=1;i--){
		mini[i]=min(mini[i+1],a[i]);
	}
	for(int i=1;i<=n;i++){
		m=max(m,a[i]);
		if(m<=mini[i+1])ans++;
	}
	cout<<ans;
	return 0;
}