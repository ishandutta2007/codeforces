#include <bits/stdc++.h>

using namespace std;

const long long d=26;
long long n,a[3];
bitset<26> vtd[26],vtd2[26],vtd3[26][26];

int main()
{
	long long t,rr,i,j,sz;
	bool bad;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		bad=0;
		for(i=0;i<d;i++)
		{
			vtd[i].reset();
			vtd2[i].reset();
			for(j=0;j<d;j++)
			{
				vtd3[i][j].reset();
			}
		}
		for(i=1;i<=n;i++)
		{
			cin>>s;
			sz=s.length();
			for(j=0;j<sz;j++)
			{
				a[j]=s[j]-'a';
			}
			for(j=0;j<sz-1-j;j++)
			{
				if(a[j]!=a[sz-1-j])
				{
					break;
				}
			}
			if(j>=sz-1-j||vtd[a[sz-1]][a[sz-2]]||sz==2&&vtd2[a[1]][a[0]]||sz==3&&vtd3[a[2]][a[1]][a[0]])
			{
				bad=1;
				continue;
			}
			if(sz==2)
			{
				vtd[a[0]][a[1]]=1;
			}
			else
			{
				vtd2[a[0]][a[1]]=1;
				vtd3[a[0]][a[1]][a[2]]=1;
			}
		}
		if(bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}