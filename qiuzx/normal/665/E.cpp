#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 30000010
using namespace std;
struct Trie{
	int lid,rid,sz;
}trie[N];
int n,k,a[1000010],cnt=0;
ll ans=0;
void add(int x,int v,int plc)
{
	trie[x].sz++;
	if(plc==-1)
	{
		return;
	}
	if(v&(1<<plc))
	{
		if(trie[x].rid==-1)
		{
			trie[x].rid=++cnt;
		}
		add(trie[x].rid,v,plc-1);
	}
	else
	{
		if(trie[x].lid==-1)
		{
			trie[x].lid=++cnt;
		}
		add(trie[x].lid,v,plc-1);
	}
	return;
}
ll query(int x,int v,int plc)
{
	if(trie[x].lid==-1&&trie[x].rid==-1)
	{
		return trie[x].sz;
	}
	bool v1=(k&(1<<plc)),v2=(v&(1<<plc));
	int x1,x2,ret=0;
	x1=v1;
	x2=v2;
	if(x2>x1)
	{
		if(trie[x].lid!=-1)
		{
			ret+=trie[trie[x].lid].sz;
		}
	}
	if(x2==x1)
	{
		if(trie[x].lid!=-1)
		{
			ret+=query(trie[x].lid,v,plc-1);
		}
	}
	if((x2^1)>x1)
	{
		if(trie[x].rid!=-1)
		{
			ret+=trie[trie[x].rid].sz;
		}
	}
	if((x2^1)==x1)
	{
		if(trie[x].rid!=-1)
		{
			ret+=query(trie[x].rid,v,plc-1);
		}
	}
	return ret;
}
int main(){
	int i,sum=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<N;i++)
	{
		trie[i].lid=trie[i].rid=-1;
		trie[i].sz=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		//printf("add %lld\n",sum);
		add(0,sum,30);
		sum^=a[i];
		//printf("query %lld\n",sum);
		ans+=query(0,sum,30);
	}
	printf("%lld\n",ans);
	return 0;
}