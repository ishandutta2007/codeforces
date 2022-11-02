#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<cassert>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define hash hsh
int T,n,go[2][4000010],v[4000010],tot;
char s[4000010];
vector<int>pos[2],g[200010];
void insert(const vector<int>&g)
{
	int p=0;
	for(auto i:g)
	{
		if(!go[i][p])go[i][p]=++tot,go[0][tot]=go[1][tot]=v[tot]=0;
		p=go[i][p];
	}
	v[p]=1;
}
bool check(const vector<int>&g)
{
	int p=0;
	for(auto i:g)
	{
		if(!go[i][p])return 0;
		p=go[i][p];
	}
	return v[p];
}
int main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&n);
		pos[0].clear();pos[1].clear();
		int cnt1=0,cnt2=0;
		rep(i,n)
		{
			scanf("%s",s+1);
			g[i].clear();
			int len=strlen(s+1);
			rep(j,len)g[i].pb(s[j]-'0');
		}
		tot=0;go[0][0]=go[1][0]=0;
		rep(i,n)insert(g[i]);
		rep(i,n)
		{
			int x=g[i][0],y=g[i].back();
			if(x==y)continue;
			reverse(g[i].begin(),g[i].end());
			if(x)cnt2++;else cnt1++;
			if(check(g[i]))continue;
			pos[x].pb(i);
		}
		if(!cnt1&&!cnt2)
		{
			bool f0=0,f1=0;
			rep(i,n)if(g[i][0])f1=1;else f0=1;
			if(f0&&f1)puts("-1");else puts("0");
			continue;
		}
		int k=abs(cnt1-cnt2)/2,from=cnt1<cnt2;
		printf("%d\n",k);rep(i,k)printf("%d%c",pos[from][i-1]," \n"[i==k]);
	}
	return 0;
}