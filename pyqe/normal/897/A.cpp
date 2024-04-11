#include <bits/stdc++.h>

using namespace std;

long long n,a[169];

int main()
{
	long long t,rr,i,k,l,w,w2;
	char ch;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld %c",&k,&l,&ch);
		w=ch-'a';
		scanf(" %c",&ch);
		w2=ch-'a';
		for(i=k;i<=l;i++)
		{
			if(a[i]==w)
			{
				a[i]=w2;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%c",(char)(a[i]+'a'));
	}
	printf("\n");
}