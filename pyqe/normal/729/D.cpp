#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,dd,nn=0;
bitset<200069> a;
pair<long long,long long> rg[200069];

int main()
{
	long long i,j,k,p,c=0;
	string s;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&dd);
	m=-m+1;
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(i=1;i<=n;i++)
	{
		if(!a[i])
		{
			c++;
			if(i==n||a[i+1])
			{
				nn++;
				rg[nn]={c,i-c};
				m+=c/d;
				c=0;
			}
		}
	}
	printf("%lld\n",m);
	for(i=1;i<=nn;i++)
	{
		k=rg[i].fr;
		p=rg[i].sc;
		for(j=0;j<k/d&&m;j++)
		{
			m--;
			printf("%lld%c",p+(k/d-j)*d," \n"[!m]);
		}
	}
}