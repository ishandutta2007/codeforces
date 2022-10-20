#include <bits/stdc++.h>
#define N 100010
using namespace std;
int main(){
	int n,x,i,j=0,k=0,t[N],num[N],ans=-1;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>t[i];
		if(!i)
		{
			x=t[i];
		}
		else if(t[i]!=x)
		{
			x=t[i];
			num[j]=i-k;
			k=i;
			j++;
			//cout<<num[j-1]<<endl;
		}
	}
	num[j]=n-k;
	//cout<<num[j]<<endl;
	for(i=1;i<=j;i++)
	{
		ans=max(ans,min(num[i],num[i-1]));
	}
	cout<<ans*2<<endl;
	return 0;
}