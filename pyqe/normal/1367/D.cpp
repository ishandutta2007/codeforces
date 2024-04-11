#include <bits/stdc++.h>

using namespace std;

long long n,fq[26],a[69],sq[69];

int main()
{
	long long t,rr,i,j,r,c;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			fq[s[i]-'a']++;
		}
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			sq[i]=-1;
		}
		for(i=25;i+1;i--)
		{
			c=0;
			for(j=1;j<=n;j++)
			{
				c+=!a[j]&&sq[j]==-1;
			}
			if(c<=fq[i])
			{
				for(j=1;j<=n;j++)
				{
					if(!a[j]&&sq[j]==-1)
					{
						sq[j]=i;
					}
				}
				for(j=1;j<=n;j++)
				{
					if(sq[j]==i)
					{
						for(r=1;r<=n;r++)
						{
							a[r]-=abs(j-r);
						}
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%c",(char)sq[i]+'a');
		}
		printf("\n");
	}
}