#include <bits/stdc++.h>
#define N 300010
using namespace std;
int n,k,a[N],i,j,l,zo=0,ans=0,b[N];
int main(){
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	j=0;
	for(i=0;i<n;)
	{
		for(;j<n;j++)
		{
			if(a[j]==0)
			{
				zo++;
			}
			if(zo>k)
			{
				break;
			}
		}
		j--;
		if(ans<j-i+1)
		{
			for(l=0;l<n;l++)
			{
				if(l>=i&&l<=j)
				{
					b[l]=1;
				}
				else
				{
					b[l]=a[l];
				}
			}
			ans=j-i+1;
		}
		while(a[i]!=0)
		{
			i++;
		}
		i++;
		j++;
		zo-=2;
	}
	cout<<ans<<endl;
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return 0;
}