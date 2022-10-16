#include <bits/stdc++.h>

using namespace std;

long long n,m,d[2];
bitset<100069> a;

int main()
{
	long long t,rr,i;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",d,d+1,&m);
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'A';
		}
		for(i=n-1;i;i--)
		{
			m-=d[a[i]]*(i==n-1||(a[i]^a[i+1]));
			if(m<0)
			{
				break;
			}
		}
		printf("%lld\n",i+1);
	}
}