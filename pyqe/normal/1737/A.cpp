#include <bits/stdc++.h>

using namespace std;

const long long mm=26;
long long n,d,fq[mm];

int main()
{
	long long t,rr,i,j;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<mm;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			fq[ch-'a']++;
		}
		for(i=0;i<d;i++)
		{
			for(j=0;j<n/d;j++)
			{
				if(!fq[j])
				{
					break;
				}
				fq[j]--;
			}
			printf("%c",(char)(j+'a'));
		}
		printf("\n");
	}
}