#include <bits/stdc++.h>
using namespace std;
int d[30]={
	0,31,59,90,120,151,181,212,243,273,304,334
},k[2000];
int main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,i,j,m,dn,p,t,it,ans=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>m>>dn>>p>>t;
		it=d[m-1]+dn;
		for(j=it-t+200;j<it+200;j++)k[j]+=p;
	}
	for(i=0;i<700;i++)ans=max(ans,k[i]);
	cout<<ans;
    return 0;
}