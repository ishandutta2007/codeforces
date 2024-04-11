#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k,x,y,a[500001],b[500001],c[500001],cnt,s;
int h[500001],to[1000001],ne[1000001];
int t[500001],qwq[500001];
bool ok[500001],tp;
int f[500001],d[500001];
ll ans;
struct p{
	int x,y;
	friend bool operator<(p i,p j){
		return a[i.x]!=a[j.x]?a[i.x]<a[j.x]:a[i.y]<a[j.y];
	}
}e[500001];
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=h[x];
	h[x]=k;
}
inline void dfs(int i,int fa){
	for(int k=h[i];k&&tp;k=ne[k]){
		if(to[k]==fa||a[to[k]]!=a[i]) continue;
		if(c[to[k]]==-1){
			c[to[k]]=c[i]^1,b[to[k]]=s;
			dfs(to[k],i);
		}
		else if(c[to[k]]==c[i]) tp=0;
	}
}
inline int find(int x){
	if(x==f[x]) return x;
	find(f[x]);
	d[x]^=d[f[x]];
	return f[x]=f[f[x]];
}
inline void work(int l,int r){
	for(int i=l;i<=r;i++){
		x=e[i].x;
		if(t[b[x]]!=l){
			t[b[x]]=l;
			qwq[b[x]]=x;
			f[x]=x;
			d[x]=0;
		}
		else f[x]=qwq[b[x]],d[x]=c[x]^c[qwq[b[x]]];
		x=e[i].y;
		if(t[b[x]]!=l){
			t[b[x]]=l;
			qwq[b[x]]=x;
			f[x]=x;
			d[x]=0;
		}
		else f[x]=qwq[b[x]],d[x]=c[x]^c[qwq[b[x]]];
	}
	bool ok=1;
	for(int i=l;i<=r&&ok;i++){
		x=find(e[i].x),y=find(e[i].y);
		if(x!=y) f[x]=y,d[x]=1^d[e[i].x]^d[e[i].y];
		else if(d[e[i].x]^d[e[i].y]^1) ok=0;
	}
	if(!ok) ans--;
}
int main(){
	cin>>n>>m>>k;
	ans=1ll*k*(k-1)/2;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(a[x]==a[y]){
			link(x,y,++s);
			link(y,x,++s);
		}
		else{
			cnt++;
			if(a[x]>a[y]) x^=y^=x^=y;
			e[cnt].x=x,e[cnt].y=y;
		}
	}
	s=0,memset(c,-1,sizeof(c)),memset(ok,1,sizeof(ok));
	for(int i=1;i<=n;i++){
		if(c[i]!=-1||!ok[a[i]]) continue;
		c[i]=0,b[i]=++s;
		tp=1,dfs(i,0);
		if(!tp){
			ans-=k-1,k--;
			ok[a[i]]=0;
		}
	}
	sort(e+1,e+1+cnt);
	for(int i=1,j;i<=cnt;i=j+1){
		for(j=i+1;j<=cnt&&a[e[j].x]==a[e[i].x]&&a[e[j].y]==a[e[i].y];j++);
		j--;
		if(ok[a[e[i].x]]&&ok[a[e[i].y]]) work(i,j);
	}
	cout<<ans;
}