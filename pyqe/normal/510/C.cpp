#include <bits/stdc++.h>

using namespace std;

long long n,z[26],c=0;
vector<long long> al[26];
bitset<26> vtd,vtd2;
bool bad;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(vtd2[l])
		{
			bad=1;
			return;
		}
		if(!vtd[l])
		{
			dfs(l);
			if(bad)
			{
				return;
			}
		}
	}
	z[c]=x;
	c++;
	vtd[x]=1;
	vtd2[x]=0;
}

int main()
{
	long long i,ln,j,k,l;
	string s,sl;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(i>0)
		{
			ln=min(sl.length(),s.length());
			bad=0;
			for(j=0;j<ln;j++)
			{
				if(sl[j]!=s[j])
				{
					k=sl[j]-'a';
					l=s[j]-'a';
					al[l].push_back(k);
					bad=1;
					break;
				}
			}
			if(!bad)
			{
				if(sl.length()>s.length())
				{
					printf("Impossible\n");
					return 0;
				}
			}
		}
		sl=s;
	}
	bad=0;
	for(i=0;i<26;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
			if(bad)
			{
				printf("Impossible\n");
				return 0;
			}
		}
	}
	for(i=0;i<26;i++)
	{
		printf("%c",(char)z[i]+'a');
	}
	printf("\n");
}