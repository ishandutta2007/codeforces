#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069];

int main()
{
	long long t,rr,i,j,ii,p,lb,rb;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
		}
		for(p=1;p<n+1-p&&a[p]==a[n+1-p];p++);
		p--;
		for(j=-1,i=n-p*2;j==-1&&i+1;i--)
		{
			for(ii=0;ii<2;ii++)
			{
				for(j=1;j<=i;j++)
				{
					if(a[p+(n-p*2-i)*ii+j]!=a[p+(n-p*2-i)*ii+i+1-j])
					{
						j=-1;
						break;
					}
				}
				if(j!=-1)
				{
					lb=p+i*!ii+1;
					rb=p+i*!ii+(n-p*2-i);
					break;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(i<lb||i>rb)
			{
				printf("%c",(char)a[i]+'a');
			}
		}
		printf("\n");
	}
}