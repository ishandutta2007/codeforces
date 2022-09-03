#include <utility>
#include <cstdio>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long LL;
typedef long double LF;
using namespace std;
class dsu
{
	public:
		int sz;
		int f[502];
		dsu()
		{
			sz=0;
			for(int i=1;i<=500;++i)
				f[i]=i;
		}
		int size()
		{
			return sz;
		}
		int greatest_father(int x)
		{
			if(f[x]==x)
				return x;
			else
				return f[x]=greatest_father(f[x]);
		}
		bool same(int x,int y)
		{
			x=greatest_father(x);
			y=greatest_father(y);
			return x==y;
		}
		void unionset(int x,int y)
		{
			x=greatest_father(x);
			y=greatest_father(y);
			if(x!=y)sz++;
			f[x]=y;
		}
}l[10002],r[10002];
pair<int,int> edge[10002];
int n,m,k,x,y;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&edge[i].ff,&edge[i].ss);
		l[i]=l[i-1];
		l[i].unionset(edge[i].ff,edge[i].ss);
	}
	for(int i=m;i>0;i--)
	{
		r[i]=r[i+1];
		r[i].unionset(edge[i].ff,edge[i].ss);
	}
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&x,&y);
		dsu tmp=l[x-1];
		for(int i=1;i<=n;++i)
			tmp.unionset(i,r[y+1].f[i]);
		printf("%d\n",n-tmp.size());
	}
	return 0;
}