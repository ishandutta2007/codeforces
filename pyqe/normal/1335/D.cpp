#include <bits/stdc++.h>

using namespace std;

long long a[9][9];

int main()
{
	long long t,rr,i,j,ti,tj;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<9;i++)
		{
			cin>>s;
			for(j=0;j<9;j++)
			{
				a[i][j]=s[j]-'0';
			}
		}
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				ti=i*3+j;
				tj=j*3+i;
				a[ti][tj]=a[ti][tj]%9+1;
			}
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf("%lld",a[i][j]);
			}
			printf("\n");
		}
	}
}