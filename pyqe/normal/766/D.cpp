#include <bits/stdc++.h>

using namespace std;

long long n,m,dsu[100069];
string as[100069];
bitset<100069> iv;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		fd(dsu[x]);
		iv[x]=iv[x]^iv[dsu[x]];
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long t,rr,i,ky,k,l;
	string s[2];
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		cin>>as[i];
		dsu[i]=i;
	}
	sort(as+1,as+n+1);
	for(i=0;i<m;i++)
	{
		scanf("%lld",&ky);
		cin>>s[0]>>s[1];
		ky--;
		k=lower_bound(as+1,as+n+1,s[0])-as;
		l=lower_bound(as+1,as+n+1,s[1])-as;
		if(fd(k)!=fd(l)||(iv[k]^iv[l])==ky)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		if(fd(k)!=fd(l))
		{
			ky^=iv[k]^iv[l];
			k=fd(k);
			l=fd(l);
			iv[l]=ky;
			dsu[l]=k;
		}
	}
	for(rr=0;rr<t;rr++)
	{
		cin>>s[0]>>s[1];
		k=lower_bound(as+1,as+n+1,s[0])-as;
		l=lower_bound(as+1,as+n+1,s[1])-as;
		printf("%lld\n",3ll-(fd(k)==fd(l))*(1+(iv[k]==iv[l])));
	}
}