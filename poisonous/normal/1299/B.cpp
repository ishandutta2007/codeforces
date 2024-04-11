#include<bits/stdc++.h>
using namespace std;
int x[200010],y[200010];
int main()
{
	int n;
	cin>>n;
	if(n%2==1)
	{
		cout<<"NO";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		x[i+n]=x[i];
		y[i+n]=y[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k=i+n/2;
		if(x[i]-x[i+1]!=x[k+1]-x[k])
		{
			cout<<"NO";
			return 0;
		}
		if(y[i]-y[i+1]!=y[k+1]-y[k])
		{
			cout<<"NO";
			return 0;
		}		
	}
	cout<<"YES";
}