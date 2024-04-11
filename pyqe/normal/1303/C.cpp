#include <bits/stdc++.h>

using namespace std;

long long ls[26][26],dg[26],sq[26],zs;
vector<long long> al[26];
bitset<26> vtd;
bool r0;

void dfs(long long x,long long ls)
{
	long long i,sz=al[x].size(),l;
	
	if(dg[x]>2)
	{
		r0=1;
		return;
	}
	vtd[x]=1;
	sq[zs]=x;
	zs++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(l==ls)
		{
			continue;
		}
		if(vtd[l])
		{
			r0=1;
			return;
		}
		dfs(l,x);
	}
}

int main()
{
	long long t,rr,i,k,l,ln;
	string s;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		cin>>s;
		ln=s.length();
		for(i=0;i<26;i++)
		{
			al[i].clear();
			dg[i]=0;
		}
		for(i=1;i<=ln;i++)
		{
			k=s[i-1]-'a';
			if(i>1)
			{
				if(ls[k][l]<rr)
				{
					al[k].push_back(l);
					al[l].push_back(k);
					dg[k]++;
					dg[l]++;
					ls[k][l]=rr;
					ls[l][k]=rr;
				}
			}
			l=k;
		}
		vtd.reset();
		zs=0;
		for(i=0;i<26;i++)
		{
			if(!vtd[i])
			{
				if(!dg[i])
				{
					sq[zs]=i;
					zs++;
				}
				else if(dg[i]==1)
				{
					r0=0;
					dfs(i,-1);
					if(r0)
					{
						break;
					}
				}
			}
		}
		if(r0||zs<26)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(i=0;i<26;i++)
			{
				printf("%c",(char)sq[i]+'a');
			}
			printf("\n");
		}
	}
}