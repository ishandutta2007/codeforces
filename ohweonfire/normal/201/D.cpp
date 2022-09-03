// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

namespace trie
{
	int ch[333][26]={},v[333],rt=1,tot=1;
	void addword(char*s,int id)
	{
		int cur=rt;
		for(int i=0;s[i];i++)
		{
			if(!ch[cur][s[i]-'a'])ch[cur][s[i]-'a']=++tot;
			cur=ch[cur][s[i]-'a'];
		}
		v[cur]=id;
	}
	int getid(char*s)
	{
		int cur=rt;
		for(int i=0;s[i];i++)
		{
			cur=ch[cur][s[i]-'a'];
			if(!cur)return -1;
		}
		return v[cur];
	}
};

#define getcode(i,j) (((i)>>(j))&1)
int nxt[500111][15],k,dp[1<<15][111],n,m,bits[1<<15],a[500111];
int calc()
{
	for(int i=0;i<n;i++)nxt[k][i]=k;
	for(int i=k-1;i>=0;i--)
	{
		memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
		nxt[i][a[i]]=i;
	}
	int mxv=n*(n-1)/2;
	for(int i=0;i<(1<<n);i++)for(int j=0;j<=mxv;j++)dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=0;i<(1<<n);i++)for(int j=0;j<=mxv;j++)if(dp[i][j]<k)
	{
		for(int nv=0;nv<n;nv++)if(!getcode(i,nv))
		{
			int ni=i|(1<<nv),nj=j+bits[i&~((1<<nv)-1)];
			dp[ni][nj]=min(dp[ni][nj],nxt[dp[i][j]][nv]+1);
		}
	}
	for(int i=0;i<=mxv;i++)if(dp[(1<<n)-1][i]<=k)return mxv-i+1;
	return 0;
}

int main()
{
	memset(trie::v,-1,sizeof(trie::v));
	for(int i=0;i<(1<<15);i++)bits[i]=__builtin_popcount(i);
	
	char s[23];
	get1(n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		trie::addword(s,i);
	}
	get1(m);
	int ans=0,ansid=0;
	for(int i=1;i<=m;i++)
	{
		get1(k);int nk=0;
		for(int j=0;j<k;j++)
		{
			scanf("%s",s);
			a[nk]=trie::getid(s);
			if(a[nk]!=-1&&(nk==0||a[nk]!=a[nk-1]))nk++;
		}
		k=nk;
		int now=calc();
		if(ans<now)
		{
			ans=now;
			ansid=i;
		}
	}
	
	if(ans==0)puts("Brand new problem!");
	else
	{
		printf("%d\n[:",ansid);
		while(ans--)putchar('|');
		puts(":]");
	}
	return 0;
}