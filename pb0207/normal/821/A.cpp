#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e2+1e1+7;

int n,a[N][N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(a[i][j]!=1)
		{
			int flag=false;
			for(int s=1;s<=n;s++)
				for(int t=1;t<=n;t++)
				{
					if(s!=j&&t!=i)
						if(a[i][j]==a[i][s]+a[t][j])
							 flag=true;
				}
			if(!flag)
			{
				cout<<"No";
				return 0;
			}
		}
	cout<<"Yes";
}