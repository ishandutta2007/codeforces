#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

int n,m,q,a[N],op[N],l[N],r[N];

int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>op[i]>>l[i]>>r[i];
	for(int i=1;i<=q;i++)
	{
		int x;
		cin>>x;
		for(int j=m;j>=1;j--)
		{
			if(op[j]==1)
			{
				if(x>=l[j]&&x<=r[j])
				{
					x--;
					if(x<l[j])
						x=r[j];
				}
			}
			else
			{
				if(x>=l[j]&&x<=r[j])
					x=(l[j]+r[j])-x;
			}
		}
		cout<<a[x]<<" ";
	}
}