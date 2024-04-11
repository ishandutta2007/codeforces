#include<cstdio>
#include<iostream>
using namespace std;
long long ans1,ans2,ans3,ans,k;
int n,m,x,y;
int main()
{
	cin>>n>>m>>k>>x>>y;
	if(n==1||n==2)
	{
		ans=k/(n*m);
		k%=(m*n);
		cout<<(ans+(k>0))<<' '<<ans<<' ';
		if((x-1)*m+y<=k)cout<<ans+1;else cout<<ans;
		return 0;
	}
	ans2=k/((2*n-2)*m);
	k%=(2*n-2)*m;
	ans1=ans2*2;
	ans3=ans2;
	if(k>m)ans1++;
	if(k>n*m)ans1++;
	if(k>=n*m)ans2++;
	if(1<x&&x<n)
	{
		ans3*=2;
		if(k>n*m)ans3+=1+((n-x-1)*m+y<=k-n*m);
		else ans3+=(x-1)*m+y<=k;
	}
	else ans3+=(x-1)*m+y<=k;
	cout<<ans1+(ans1==0)<<' '<<ans2<<' '<<ans3;
	return 0;
}