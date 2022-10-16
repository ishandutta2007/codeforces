#include <bits/stdc++.h>

using namespace std;

long long n,m,d,sq[1069][1069];
bitset<1069> a[1069];
string ky="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main()
{
	long long t,rr,i,j,c,p,k,fq;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		fq=0;
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=1;j<=m;j++)
			{
				a[i][j]=s[j-1]=='R';
				fq+=a[i][j];
			}
		}
		p=0;
		c=0;
		for(i=1;i<=n;i++)
		{
			for(j=1+i%2*(m-1);j!=m+1-i%2*(m+1);j+=1-i%2*2)
			{
				c+=a[i][j];
				k=fq/d;
				if(p<fq%d)
				{
					k++;
				}
				if(c>k)
				{
					p++;
					c=1;
				}
				sq[i][j]=p;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%c",ky[sq[i][j]]);
			}
			printf("\n");
		}
	}
}