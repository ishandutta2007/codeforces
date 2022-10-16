#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],aa[100069],ky[7]={0,1,0,2,0,1,0};

int main()
{
	long long t,rr,i,j,r,c;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
			if(s[i-1]=='?')
			{
				a[i]=-1;
			}
		}
		c=0;
		for(i=1;i<=n-6;i++)
		{
			for(j=0;j<7;j++)
			{
				if(a[i+j]!=ky[j])
				{
					j=-1;
					break;
				}
			}
			c+=j!=-1;
		}
		if(!c)
		{
			for(i=1;i<=n-6;i++)
			{
				for(j=0;j<7;j++)
				{
					if(a[i+j]!=ky[j]&&a[i+j]!=-1)
					{
						j=-1;
						break;
					}
				}
				if(j!=-1)
				{
					for(j=0;j<7;j++)
					{
						aa[i+j]=a[i+j];
						a[i+j]=ky[j];
					}
					for(j=max(i-6,1ll);j<=min(i+6,n-6);j++)
					{
						if(j!=i)
						{
							for(r=0;r<7;r++)
							{
								if(a[j+r]!=ky[r])
								{
									r=-1;
									break;
								}
							}
							if(r!=-1)
							{
								j=-1;
								break;
							}
						}
					}
					if(j!=-1)
					{
						c++;
						break;
					}
					for(j=0;j<7;j++)
					{
						a[i+j]=aa[i+j];
					}
				}
			}
		}
		if(c!=1)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
			for(i=1;i<=n;i++)
			{
				if(a[i]==-1)
				{
					a[i]=3;
				}
				printf("%c",(char)a[i]+'a');
			}
			printf("\n");
		}
	}
}