#include<bits/stdc++.h>
using namespace std;
int x[1000010];
int y[35],z[35];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++)
		for(int j=30;j>=0;j--)
		{
			if(x[i]&(1<<j))
			{
				y[j]++;
				z[j]=i;
			}
		}
	for(int j=30;j>=0;j--)
		if(y[j]==1)
		{
			cout<<x[z[j]]<<' ';
			for(int i=1;i<=n;i++)
				if(i!=z[j])
					cout<<x[i]<<' ';
				
			return 0;
		}
			for(int i=1;i<=n;i++)
					cout<<x[i]<<' ';	
}