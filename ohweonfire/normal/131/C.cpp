#include <iostream>
using namespace std;
long long c[100][100];
int n,m,t;
int main()
{
	for(int i=0;i<100;i++)c[i][0]=1;
	for(int i=1;i<=90;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	
	cin>>n>>m>>t;
	long long sum=0;
	for(int i=4;i<t;i++)
	{
		int j=t-i;
		if(j>m)continue;
		if(j<1)continue;
		sum+=c[n][i]*1ll*c[m][j];
	}
	cout<<sum;
	return 0;
}