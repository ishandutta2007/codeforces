#include<iostream>
#include<cstdio>
using namespace std;
#define N (int)1e5+2
int a[N],b[N],ans[N],a2,a1,b2,b1,p2,p1;
int main()
{
	int n,flag=0;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	scanf("%d",&b[i]);
	for(i=1;i<n;i++)
	{
		a2=a[i]/2,b2=b[i]/2,a1=a[i]%2,b1=b[i]%2;
		if((!a2)&&b2)break;
		if((!a1)&&b1)break;
	}
	if(i<n)
	{
	    cout<<"NO";	
	    return 0;
	}
	ans[0]=0;
	for(i=1;i<n;i++)
	{
		ans[i]=0;
		a2=a[i]/2,b2=b[i]/2,a1=a[i]%2,b1=b[i]%2,p2=ans[i-1]/2,p1=ans[i-1]%2;
		//cout<<"what\n";
	    if(p2)
		{
			if(!a2)break;
			if(b2)ans[i]+=2;	
		}
		else 
		{
			if(b2)break;
			if(a2)ans[i]+=2;	
		}
		if(p1)
		{
			if(!a1)break;
			if(b1)ans[i]+=1;
		}	
		else
		{
			if(b1)break;
			if(a1)ans[i]+=1;
		}
	}
	//cout<<i<<' '<<n;
	if(i==n)
	{
	    cout<<"YES\n";
		for(j=0;j<n;j++)
		printf("%d ",ans[j]);
		return 0;	
	}
	//cout<<"yes\n"; 
	ans[0]=1;
	for(i=1;i<n;i++)
	{
		ans[i]=0;
		a2=a[i]/2,b2=b[i]/2,a1=a[i]%2,b1=b[i]%2,p2=ans[i-1]/2,p1=ans[i-1]%2;
	    if(p2)
		{
			if(!a2)break;
			if(b2)ans[i]+=2;	
		}
		else 
		{
			if(b2)break;
			if(a2)ans[i]+=2;	
		}
		if(p1)
		{
			if(!a1)break;
			if(b1)ans[i]+=1;
		}	
		else
		{
			if(b1)break;
			if(a1)ans[i]+=1;
		}
	}
	if(i==n)
	{
	    cout<<"YES\n";
		for(j=0;j<n;j++)
		printf("%d ",ans[j]);
		return 0;	
	}
	ans[0]=2;
	for(i=1;i<n;i++)
	{
		ans[i]=0;
		a2=a[i]/2,b2=b[i]/2,a1=a[i]%2,b1=b[i]%2,p2=ans[i-1]/2,p1=ans[i-1]%2;
	    if(p2)
		{
			if(!a2)break;
			if(b2)ans[i]+=2;	
		}
		else 
		{
			if(b2)break;
			if(a2)ans[i]+=2;	
		}
		if(p1)
		{
			if(!a1)break;
			if(b1)ans[i]+=1;
		}	
		else
		{
			if(b1)break;
			if(a1)ans[i]+=1;
		}
	}
	if(i==n)
	{
	    cout<<"YES\n";
		for(j=0;j<n;j++)
		printf("%d ",ans[j]);
		return 0;	
	}
	ans[0]=3;
	for(i=1;i<n;i++)
	{
		ans[i]=0;
		a2=a[i]/2,b2=b[i]/2,a1=a[i]%2,b1=b[i]%2,p2=ans[i-1]/2,p1=ans[i-1]%2;
	    if(p2)
		{
			if(!a2)break;
			if(b2)ans[i]+=2;	
		}
		else 
		{
			if(b2)break;
			if(a2)ans[i]+=2;	
		}
		if(p1)
		{
			if(!a1)break;
			if(b1)ans[i]+=1;
		}	
		else
		{
			if(b1)break;
			if(a1)ans[i]+=1;
		}
	}
	if(i==n)
	{
	    cout<<"YES\n";
		for(j=0;j<n;j++)
		printf("%d ",ans[j]);
		return 0;	
	}
	cout<<"NO";
	return 0;
}