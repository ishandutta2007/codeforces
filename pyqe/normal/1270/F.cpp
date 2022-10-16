#include <bits/stdc++.h>

using namespace std;

long long n,sqn=447,ls[469],ps[200069];
int fq[89400069];
bitset<200069> a;

int main()
{
	long long i,j,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
		if(a[i])
		{
			for(j=sqn;j-1;j--)
			{
				ls[j]=ls[j-1];
			}
			ls[1]=i;
		}
		for(j=1;j<sqn;j++)
		{
			z+=max((i-ls[j+1])/j*j-max((i-ls[j])/j,sqn)*j,0ll)/j;
		}
	}
	fq[n]++;
	for(i=1;i<=sqn;i++)
	{
		for(j=1;j<=n;j++)
		{
			ps[j]=ps[j-1]+i*a[j]-1;
			z+=fq[n+ps[j]];
			fq[n+ps[j]]++;
		}
		for(j=1;j<=n;j++)
		{
			fq[n+ps[j]]--;
		}
	}
	printf("%lld\n",z);
}