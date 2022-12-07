#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int k=0;
	int x=-1;
	for(int i=1;i<=n;i++)
	{
		k+=(i-1)/2;
		if(k>=m)
		{
			x=i-1;
			k-=(i-1)/2;
			break;
		}
	}
	if(x==-1)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=x+1;;i++)
	{
		int p=0;
		for(int j=1;j<=x;j++)
			if((i-j>j)&&(i-j<=x))
				p++;
		if(k+p==m)
		{
			for(int j=1;j<=x;j++)
				cout<<j<<' ';
			cout<<i<<' ';
			for(int j=1000000000-((n-x)-2)*20000;j<=1000000000;j+=20000)
				cout<<j<<' ';
			cout<<endl;
			return 0;
		}
	}
	
		
}