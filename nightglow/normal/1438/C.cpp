#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>
#include<vector>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 100005

using namespace std;

int i,j,m,n,p,k,a[105][105],now;

map<int,vector<pair<int,int> > >mp;

void Main()
{
	scanf("%d%d",&n,&m);
	mp.clear();
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j) scanf("%d",&a[i][j]),mp[a[i][j]].pb(mk(i,j));
	for (map<int,vector<pair<int,int> > >::iterator it=mp.begin();it!=mp.end();++it)
	{
			now^=1;
			vector<pair<int,int> > v=it->second;
			for (int i=0;i<v.size();++i)
			{
					if (((v[i].fi+v[i].se)&1)==now) a[v[i].fi][v[i].se]++;
			}
	}
	for (i=1;i<=n;++i)
	{
		for (j=1;j<m;++j) printf("%d ",a[i][j]);
		printf("%d\n",a[i][j]);	
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for (;T--;) Main();
}