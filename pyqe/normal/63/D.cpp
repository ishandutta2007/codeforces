#include <bits/stdc++.h>

using namespace std;

long long n[2],m[2],d,a[100069],sq[1069][1069];

int main()
{
	long long i,j,u,p,c=0,lb,rb,e;
	char ch;
	
	scanf("%lld%lld%lld%lld%lld",m,n,m+1,n+1,&d);
	for(i=1;i<=d;i++)
	{
		scanf("%lld",a+i);
		a[i]+=a[i-1];
	}
	for(p=0,i=1;i<=max(n[0],n[1]);i++)
	{
		lb=1+m[0]*(i>n[0]);
		rb=m[0]+m[1]-m[1]*(i>n[1]);
		e=(i+min(n[0],n[1])+(n[0]>n[1]))%2;
		u=!e*2-1;
		for(j=!e?lb:rb;j>=lb&&j<=rb;j+=u)
		{
			c++;
			for(;a[p]<c;p++);
			sq[i][j]=p;
		}
	}
	printf("YES\n");
	for(i=1;i<=max(n[0],n[1]);i++)
	{
		for(j=1;j<=m[0]+m[1];j++)
		{
			if(!sq[i][j])
			{
				ch='.';
			}
			else
			{
				ch=sq[i][j]-1+'a';
			}
			printf("%c",ch);
		}
		printf("\n");
	}
}