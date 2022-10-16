#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],fq[26];

int main()
{
	long long t,rr,i,j,sm,p;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'a';
			sm+=d*(fq[a[i]]%d==0);
			fq[a[i]]++;
			sm--;
		}
		if(n%d)
		{
			printf("-1\n");
			continue;
		}
		if(sm)
		{
			for(i=n;i;i--)
			{
				fq[a[i]]--;
				sm+=1-d*(fq[a[i]]%d==0);
				for(j=a[i]+1;j<26;j++)
				{
					sm+=d*(fq[j]%d==0);
					fq[j]++;
					sm--;
					if(sm<=n-i)
					{
						break;
					}
					fq[j]--;
					sm+=1-d*(fq[j]%d==0);
				}
				if(j<26)
				{
					a[i]=j;
					for(p=i,j=0;j<n-i-sm;j++)
					{
						p++;
						a[p]=0;
					}
					for(j=0;j<26;j++)
					{
						for(;fq[j]%d;fq[j]++)
						{
							p++;
							a[p]=j;
						}
					}
					break;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%c",(char)a[i]+'a');
		}
		printf("\n");
	}
}