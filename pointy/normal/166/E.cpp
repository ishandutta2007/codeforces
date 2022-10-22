#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n;
int a[4][2];
int main()
{
	cin >> n;
	a[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<4;j++)
		{
			a[j][i%2]=0;
			for (int k=0;k<4;k++)
			{
				if (k==j) continue;
				a[j][i%2]=(a[j][i%2]+a[k][(i-1)%2])%mod;
			}
		}
	}
	cout << a[0][n%2];
	return 0;
}