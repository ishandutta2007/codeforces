#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ttl=0,sm[16],mm[16],pr[1<<15],pw2[16];
vector<long long> a[16];
map<long long,long long> pst;
bitset<16> vtd2;
bitset<1<<15> dp;
pair<pair<long long,long long>,long long> tmp;
vector<pair<pair<long long,long long>,long long>> v,sq[1<<15];
pair<long long,long long> z[16];

void dfs(long long mk)
{
	long long i,sz=sq[mk].size();
	
	if(sz)
	{
		for(i=0;i<sz;i++)
		{
			z[sq[mk][i].sc]=sq[mk][i].fr;
		}
	}
	else
	{
		dfs(pr[mk]);
		dfs(mk-pr[mk]);
	}
}

int main()
{
	long long i,j,r,k,l,p,mk,mkk,mkkk;
	
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
	{
		pw2[i]=1<<i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",mm+i);
		for(j=0;j<mm[i];j++)
		{
			scanf("%lld",&k);
			a[i].push_back(k);
			sm[i]+=k;
			ttl+=k;
			pst[k]=i;
		}
	}
	if(ttl%n!=0)
	{
		printf("No\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<mm[i];j++)
		{
			l=a[i][j];
			v.clear();
			vtd2.reset();
			vtd2[0]=1;
			for(p=l;!vtd2[pst[p]];)
			{
				vtd2[pst[p]]=1;
				tmp.fr.sc=pst[p];
				p+=ttl/n-sm[pst[p]];
				tmp.fr.fr=p;
				tmp.sc=pst[p];
				v.push_back(tmp);
			}
			if(p==l)
			{
				mk=0;
				for(r=n;r>0;r--)
				{
					mk=mk*2+vtd2[r];
				}
				sq[mk]=v;
				dp[mk]=1;
			}
		}
	}
	for(mk=1;mk<pw2[n];mk++)
	{
		for(mkk=mk;!dp[mk]&&mkk;mkk=(mkk-1&mk))
		{
			mkkk=mk-mkk;
			if(dp[mkk]&&dp[mkkk])
			{
				dp[mk]=1;
				pr[mk]=mkk;
			}
		}
	}
	if(dp[pw2[n]-1])
	{
		printf("Yes\n");
		dfs(pw2[n]-1);
		for(i=1;i<=n;i++)
		{
			printf("%lld %lld\n",z[i].fr,z[i].sc);
		}
	}
	else
	{
		printf("No\n");
	}
}