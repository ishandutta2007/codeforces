#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_set>
#include<map>
#include<bitset>
#include<vector>
using namespace std;
typedef long long ll;
int n,m,pn=1e6+100,sn=500,a[3000005],f[3000005],vis[3000005];
int b[100005],bt,t,ct;
ll c[20000005];
//bitset<1000005> val[1005];
unordered_set<ll> st;
vector<int> val[1100005];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),vis[a[i]]=1;
	for(int i=1;i<=2*pn;i++)
		f[i]=i;
	for(int i=2;i<=pn;i++)
		for(int j=i;j<=pn;j+=i)
			if(vis[j]) link(i+pn,j);
	for(int i=2;i<=pn;i++)
	{
		if(!vis[i-1]) continue;
		bt=0;
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				if(j!=1&&find(j+pn)<=pn) b[++bt]=find(j+pn);
				if(j*j!=i&&find(i/j+pn)<=pn) b[++bt]=find(i/j+pn);
			}
		}
		sort(b+1,b+bt+1);
		bt=unique(b+1,b+bt+1)-b-1;
		for(int j=1;j<=bt;j++)
			val[find(i-1)].push_back(b[j]);
		for(int j=1;j<=bt;j++)
			for(int k=j+1;k<=bt;k++)
				val[b[j]].push_back(b[k]);
	}
	for(int i=1;i<=pn;i++)
		sort(val[i].begin(),val[i].end());
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u=find(a[u]),v=find(a[v]);
		int fl=0;
		vector<int>::iterator it=lower_bound(val[u].begin(),val[u].end(),v);
		if(it!=val[u].end()&&*it==v) fl=1;
		it=lower_bound(val[v].begin(),val[v].end(),u);
		if(it!=val[v].end()&&*it==u) fl=1;
	//	for(int j=1;j<=t;j++)
	//		if(val[j][u]&&val[j][v])
	//			fl=1;
	//	printf("fl=%d\n",fl);
		if(u==v) printf("0\n");
		else if(fl)
			printf("1\n");
		else printf("2\n");
	}
	return 0;
}