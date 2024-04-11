#include<bits/stdc++.h>
using namespace std;

const int M=2005;
int f[5],n,a[M];

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		f[1]=f[1]+(a[i]==1?1:0);
		f[2]=max(f[1],f[2]+(a[i]==2?1:0));
		f[3]=max(f[2],f[3]+(a[i]==1?1:0));
		f[4]=max(f[3],f[4]+(a[i]==2?1:0));
	}
	cout<<f[4];
	return 0;
}