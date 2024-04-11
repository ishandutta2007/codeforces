#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,p,p2;
	
	scanf("%lld%lld",&n,&d);
	p=0;
	p2=0;
	for(i=1;i<=n;i++)
	{
		printf("%c",(char)p+'a');
		if(p<p2)
		{
			swap(p,p2);
		}
		else
		{
			swap(p,p2);
			p2++;
			if(p2>=d)
			{
				p++;
				p2=p;
				if(p>=d)
				{
					p=0;
					p2=0;
				}
			}
		}
	}
}