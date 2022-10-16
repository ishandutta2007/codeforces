#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n[2],a[2][100069];
pair<long long,long long> pst[100069];
bitset<100069> vtd;

int main()
{
	long long t,rr,i,ii,j;
	string s;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			n[ii]=s.length();
			for(i=1;i<=n[ii];i++)
			{
				a[ii][i]=s[i-1]-'A';
			}
		}
		for(i=1;i<=n[0];i++)
		{
			pst[i]={a[0][i],i};
			vtd[i]=0;
		}
		sort(pst+1,pst+n[0]+1);
		for(j=1,i=1;i<=n[0];i++)
		{
			vtd[pst[i].sc]=1;
			for(;vtd[j];j++);
			if((i==n[0]||pst[i].fr<pst[i+1].fr)&&pst[i].sc>j)
			{
				swap(a[0][j],a[0][pst[i].sc]);
				break;
			}
		}
		if(n[0]<n[1])
		{
			bad=0;
		}
		else
		{
			bad=1;
		}
		for(i=1;i<=min(n[0],n[1]);i++)
		{
			if(a[0][i]<a[1][i])
			{
				bad=0;
				break;
			}
			else if(a[0][i]>a[1][i])
			{
				bad=1;
				break;
			}
		}
		if(bad)
		{
			printf("---\n");
		}
		else
		{
			for(i=1;i<=n[0];i++)
			{
				printf("%c",a[0][i]+'A');
			}
			printf("\n");
		}
	}
}