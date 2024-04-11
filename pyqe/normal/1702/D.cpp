#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[200069];
pair<long long,long long> as[200069];
bitset<200069> spc;

int main()
{
	long long t,rr,i,k,l;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a'+1;
			as[i]={a[i],i};
			spc[i]=0;
		}
		sort(as+1,as+n+1);
		scanf("%lld",&d);
		for(i=1;i<=n;i++)
		{
			k=as[i].fr;
			l=as[i].sc;
			d-=k;
			if(d<0)
			{
				break;
			}
			spc[l]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(spc[i])
			{
				printf("%c",(char)(a[i]-1+'a'));
			}
		}
		printf("\n");
	}
}