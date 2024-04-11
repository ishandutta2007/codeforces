#include<bits/stdc++.h>
using namespace std;

int n,m;
const int M=105;
int a[M];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		for (int i=x;i<=y;i++)
			a[i]++;
	}
	for (int i=1;i<=n;i++)
		if (a[i]!=1)
			{cout<<i<<' '<<a[i];return 0;}
	cout<<"OK";
	return 0;
}