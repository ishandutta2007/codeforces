#include <bits/stdc++.h>

using namespace std;

long long n,nn,vl[1000069],ps[1000069];

int main()
{
	long long tt,rrr,t,rr,i,u,k,l;
	string s;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		cin>>s;
		n=s.length();
		nn=0;
		for(i=1;i<=n;i++)
		{
			if(s[i-1]=='['||s[i-1]==']')
			{
				nn++;
				vl[nn]=i;
				u=i%2*2-1;
				ps[nn]=ps[nn-1]+u;
			}
		}
		scanf("%lld",&t);
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld%lld",&k,&l);
			k=lower_bound(vl+1,vl+nn+1,k)-vl-1;
			l=upper_bound(vl+1,vl+nn+1,l)-vl-1;
			printf("%lld\n",abs(ps[l]-ps[k]));
		}
	}
}