#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,pair<long long,long long>> a[100069];

int main()
{
	long long t,rr,i,lb,rb,k,l,w,df;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&lb);
		rb=lb;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&w,&k,&l);
			a[i]={w,{k,l}};
		}
		sort(a+1,a+n+1);
		w=0;
		for(i=1;i<=n;i++)
		{
			k=a[i].sc.fr;
			l=a[i].sc.sc;
			df=w;
			w=a[i].fr;
			df=w-df;
			lb-=df;
			rb+=df;
			lb=max(lb,k);
			rb=min(rb,l);
			if(lb>rb)
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}