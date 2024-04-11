#include <bits/stdc++.h>

using namespace std;

const long long mm=26;
long long n,a[200069],fq[mm];

int main()
{
	long long t,rr,i;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<mm;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
			fq[a[i]]++;
		}
		for(i=1;i<=n;i++)
		{
			if(fq[a[i]]==1)
			{
				break;
			}
			fq[a[i]]--;
		}
		for(;i<=n;i++)
		{
			printf("%c",(char)(a[i]+'a'));
		}
		printf("\n");
	}
}