#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e4+1e3+7;

long long n,a[N],d0,d1,d2,sum1,sum2,s[N],ans=-1e18;

long long S(int l,int r)
{
	return s[r]-s[l];
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	for(int i=0;i<=n;i++)
	{
		sum1=-1e18,sum2=-1e18;
		int tmp0,tmp2;
		for(int j=0;j<=i;j++)
			if(S(0,j)-S(j,i)>sum1)
				sum1=S(0,j)-S(j,i),tmp0=j;
		for(int j=i;j<=n;j++)
			if(S(i,j)-S(j,n)>sum2)
				sum2=S(i,j)-S(j,n),tmp2=j;
		if(sum1+sum2>ans)
			ans=sum1+sum2,d0=tmp0,d2=tmp2,d1=i;
	}
	cout<<d0<<" "<<d1<<" "<<d2;
}