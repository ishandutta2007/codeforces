#include <bits/stdc++.h>
#define N 100010
using namespace std;
long long n,d,a[N],mxm[N],ans=0;
int main(){
	long long x,i;
	cin>>n>>d;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mxm[n-1]=min(d,d-a[n-1]);
	for(i=n-2;i>=0;i--)
	{
		mxm[i]=min(min(d,d-a[i]),mxm[i+1]-a[i]);
		if(a[i]==0&&mxm[i]<0)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	x=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			if(x<0)
			{
				x=mxm[i];
				ans++;
			}
		}
		else
		{
			if(x>mxm[i])
			{
				cout<<-1<<endl;
				return 0;
			}
			x+=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}