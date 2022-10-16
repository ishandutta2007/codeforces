#include <bits/stdc++.h>

using namespace std;

long long n;
map<pair<long long,long long>,long long> a;

int main()
{
	long long t,rr,k,l,w,c=0,c2=0;
	char ch;
	
	scanf("%lld%lld",&n,&t);
	for(rr=0;rr<t;rr++)
	{
		scanf(" %c%lld",&ch,&k);
		if(ch=='+')
		{
			scanf("%lld %c",&l,&ch);
			w=ch-'a'+1;
			c+=!!a[{l,k}];
			c2+=a[{l,k}]==w;
			a[{k,l}]=w;
		}
		else if(ch=='-')
		{
			scanf("%lld",&l);
			w=a[{k,l}];
			c-=!!a[{l,k}];
			c2-=a[{l,k}]==w;
			a[{k,l}]=0;
		}
		else
		{
			if(c2||(c&&k%2))
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