#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=3010;
const int M=(int)2e5+10;
int f[N],c[M],in[N],l[N],r[N],n,a[N],minl,maxr;
vector<int>g[N];
queue<int>q;
void modify(int x,int y){for(;x<=maxr;x+=x&(-x))c[x]=max(c[x],y);}
void clear(int x){for(;x<=maxr;x+=x&(-x))c[x]=0;}
int get(int x){int s=0;for(;x;x-=x&(-x))s=max(s,c[x]);return s;}
int cmp(int x,int y){return l[x]<l[y];}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		minl=(int)2e5;maxr=0;
		rep(i,n)scanf("%d%d",&l[i],&r[i]),minl=min(minl,l[i]),maxr=max(maxr,r[i]);
		n++;l[n]=minl;r[n]=++maxr;
		rep(i,n)g[i].clear();
		rep(i,n)rep(j,n)if(i!=j&&l[i]<=l[j]&&r[j]<=r[i])g[i].pb(j),in[j]++;
		q.push(n);
		int cnt=0;
		for(;!q.empty();)
		{
			int u=q.front();q.pop();a[++cnt]=u;
			for(auto i:g[u])
			{
				in[i]--;
				if(!in[i])q.push(i);
			}
		}
		rep(i,n)sort(g[i].begin(),g[i].end(),cmp);
		for(int i=cnt;i;i--)
		{
			int x=a[i];
			for(auto j:g[x])modify(r[j],f[j]+get(l[j]-1));
			f[x]=get(r[x])+1;
			for(auto j:g[x])clear(r[j]);
		}
		printf("%d\n",f[n]-1);
	}
	return 0;
}