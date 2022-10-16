#include <bits/stdc++.h>

using namespace std;

long long n,m,nn,aa[569],a[1069],ca[1069],faf[1069];

int main()
{
	long long t,rr,i,j,r,c;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			aa[i]=s[i-1]-'a';
		}
		cin>>s;
		m=s.length();
		for(i=1;i<=m;i++)
		{
			a[i]=s[i-1]-'a';
		}
		for(i=1;i<=m;i++)
		{
			nn=max(m+1-i,i);
			for(j=1;j<=nn;j++)
			{
				if(i+j-1<=m&&i-j+1>0&&a[i+j-1]!=a[i-j+1])
				{
					break;
				}
				if(i+j-1<=m)
				{
					ca[j]=a[i+j-1];
				}
				else
				{
					ca[j]=a[i-j+1];
				}
			}
			if(j>nn)
			{
				faf[0]=-1;
				for(j=1;j<=nn;j++)
				{
					for(r=faf[j-1];r+1&&ca[r+1]!=ca[j];r=faf[r]);
					faf[j]=r+1;
				}
				c=0;
				for(j=n;j;j--)
				{
					for(;c+1&&ca[c+1]!=aa[j];c=faf[c]);
					c++;
					if(c==nn)
					{
						break;
					}
				}
				if(j)
				{
					break;
				}
			}
		}
		if(i<=m)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}