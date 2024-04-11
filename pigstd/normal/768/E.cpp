#include<bits/stdc++.h>
using namespace std;

const int M=1e6+10;
int n;
int a[M],f[M];

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int sum=0;
		for (int j=1;;j++)
		{
			sum+=j;
			if (sum>a[i])
			{
				f[i]=j-1;
				break;
			}
		}
	}
	int k=f[1];
	for (int i=2;i<=n;i++)
		k^=f[i];
	if (k==0)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}