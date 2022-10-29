#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
// head

const int N=2e6+5;

int n,ans,a[N],b[N];
int ed,nd;
int head[N],nxt[N<<1],to[N<<1],id[N<<1],tot;
bool mark[N],vis[N];
pii mx;

void add_edge(int u,int v,int iid) {
	nxt[++tot]=head[u],head[u]=tot,to[tot]=v,id[tot]=iid;	
}

void dfs(int u) {
	vis[u]=1,nd++;
	if (u>mx.fi) mx.se=mx.fi,mx.fi=u;
	else if (u>mx.se) mx.se=u;
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i],iid=id[i];
		if (!mark[iid]) mark[iid]=1,ed++;
		if (vis[v]) continue;
		dfs(v);
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		int u,v;
		scanf("%d%d",&u,&v);
		a[2*i]=u,a[2*i-1]=v;
		b[2*i]=u,b[2*i-1]=v;
	}
	int m=2*n;
	sort(b+1,b+1+m);
	m=unique(b+1,b+1+m)-b-1;
	rep(i,1,n+1) {
		int u,v;
		u=a[2*i]=lower_bound(b+1,b+1+m,a[2*i])-b;
		v=a[2*i-1]=lower_bound(b+1,b+1+m,a[2*i-1])-b;
		add_edge(u,v,i);
		add_edge(v,u,i);
	}
	rep(i,1,2*n+1) if (!vis[a[i]]) {
		mx=mp(0,0);
		ed=nd=0;
		dfs(a[i]);
		if (ed>nd) return puts("-1"),0;
		else if (ed==nd) ans=max(ans,b[mx.fi]);
		else ans=max(ans,b[mx.se]);
	}
	printf("%d\n",ans);
	return 0;
}