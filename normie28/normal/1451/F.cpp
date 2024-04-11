#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,u,v,a,b,t,t1;
int arr[1001][1001];
int diag[1001];
int main()
{
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>m;
		for (i=0;i<=n+m-2;i++) diag[i]=0;
		for (i=0;i<n;i++)
			for (j=0;j<m;j++)
			{
				cin>>arr[i][j];
				diag[i+j]^=arr[i][j];
			}
		a=0;
		for (i=0;i<=n+m-2;i++) a+=diag[i];
		if (a) cout<<"Ashish\n"; else cout<<"Jeel\n";
	}
}