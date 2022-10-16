#include <bits/stdc++.h>

using namespace std;

long long n,a[2][1000069],tmp[1000069];

bool chk()
{
	long long i;
	
	if(n<=3)
	{
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		tmp[i]=a[0][i];
	}
	for(i=n-3;tmp[i];i--)
	{
		tmp[i]=0;
	}
	tmp[i]=1;
	for(i=1;i<=n-2;i++)
	{
		if(tmp[i]!=a[1][i])
		{
			return tmp[i]<a[1][i];
		}
	}
	return 1;
}

int main()
{
	long long i,ii,p,w[2],z;
	char ch;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[ii][i]=ch-'0';
		}
		w[ii]=a[ii][n-1]*2+a[ii][n];
	}
	for(p=1;p<=n&&a[0][p]==a[1][p];p++);
	if(p==1)
	{
		for(i=0;i<n;i++)
		{
			printf("1");
		}
		printf("\n");
		return 0;
	}
	if(w[1]==3||(w[1]==2&&(!w[0]||p<=n-2)))
	{
		z=3;
	}
	else if(w[1]==2)
	{
		z=2;
	}
	else if(w[1]==1||(!w[1]&&p<=n-2&&(w[0]<=2||chk())))
	{
		z=1;
	}
	else
	{
		z=0;
	}
	a[1][n-1]=z/2;
	a[1][n]=z%2;
	for(i=1;i<=n;i++)
	{
		printf("%lld",a[1][i]);
	}
	printf("\n");
}