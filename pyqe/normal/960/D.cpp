#include <bits/stdc++.h>

using namespace std;

const long long mm=60;
long long lz[mm];

int main()
{
	long long t,rr,i,ky,k,l,w,c,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			scanf("%lld",&l);
			for(c=0;k>1;k/=2,c++);
			w=1ll<<c;
			l=(-l%w+w)%w;
			lz[c]=(lz[c]+l)%w;
		}
		else if(ky==2)
		{
			scanf("%lld",&l);
			for(c=0;k>1;k/=2,c++);
			w=1ll<<c;
			l=(-l%w+w)%w;
			for(i=c;i<mm;i++)
			{
				lz[i]=(lz[i]+l)%w;
				l<<=1;
				w<<=1;
			}
		}
		else
		{
			p=k;
			for(c=0;k>1;k/=2,c++);
			w=1ll<<c;
			for(;1;c--)
			{
				printf("%lld%c",p," \n"[p==1]);
				if(p==1)
				{
					break;
				}
				p=(p-lz[c])%w+w>>1;
				w>>=1;
				p=(p-w+lz[c-1])%w+w;
			}
		}
	}
}