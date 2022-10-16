#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> ft,ls;

int main()
{
	long long tt,rrr,t,rr,i,k,l;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		ft.clear();
		ls.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(!ft[k])
			{
				ft[k]=i;
			}
			ls[k]=i;
		}
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld%lld",&k,&l);
			if(ft[k]&&ft[l]&&ft[k]<ls[l])
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
}