#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,pz[1000069],sbt[1000069],sq[1000069];
vector<pair<long long,long long>> al[1000069];

void dfs(long long x,long long w,long long w2)
{
	long long i,sz=al[x].size(),l;
	
	sort(al[x].begin(),al[x].end());
	if(pz[x])
	{
		sbt[x]++;
		w=min(w,w2+1);
		sq[pz[x]]=w;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].sc;
		dfs(l,w+1,min(w2+sbt[x],w+1));
		sbt[x]+=sbt[l];
	}
}

int main()
{
	long long i,k;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %c",&k,&ch);
		al[k].push_back({ch,i});
	}
	scanf("%lld",&d);
	for(i=1;i<=d;i++)
	{
		scanf("%lld",&k);
		pz[k]=i;
	}
	dfs(0,0,0);
	for(i=1;i<=d;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==d]);
	}
}