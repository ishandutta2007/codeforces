#include <bits/stdc++.h>

using namespace std;

long long ln,a[100069];
multiset<long long> ms[26];

int main()
{
	long long t,rr,i,ky,k,l,c;
	string s;
	char ch;
	
	cin>>s;
	ln=s.length();
	for(i=1;i<=ln;i++)
	{
		a[i]=s[i-1]-'a';
		ms[a[i]].insert(i);
	}
	for(i=0;i<26;i++)
	{
		ms[i].insert(ln+1);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			scanf(" %c",&ch);
			l=ch-'a';
			ms[a[k]].erase(ms[a[k]].find(k));
			ms[l].insert(k);
			a[k]=l;
		}
		else if(ky==2)
		{
			scanf("%lld",&l);
			c=0;
			for(i=0;i<26;i++)
			{
				if(*ms[i].lower_bound(k)<=l)
				{
					c++;
				}
			}
			printf("%lld\n",c);
		}
	}
}