#include<bits/stdc++.h>
using namespace std;

const int M=105;
int n,a[M];

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				if (!((i==j)||(j==k)||(i==k)))
					if (a[i]+a[j]==a[k])
						{cout<<k<<' '<<i<<' '<<j;return 0;}
	cout<<-1;
	return 0;
}