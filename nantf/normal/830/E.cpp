#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353,INF=1e9;
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,el,head[maxn],to[maxn],nxt[maxn],deg[maxn];
int x,y,z,e,p,id[maxn],cnt,ans[maxn],len[maxn],tmp[maxn],dep[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	id[u]=cnt;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(id[v]) continue;
		dfs(v);
	}
	if(deg[u]>=4) x=u;
	if(deg[u]>=3){
		if(!y) y=u;
		else z=u;
	}
	p++;
	e+=deg[u];
}
bool dfs1(int u,int f){
	if(u==z) return ans[u]=2,true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(dfs1(v,u)) return ans[u]=2,true;
	}
	return false;
}
void dfs2(int u,int f){
	len[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs2(v,u);
		len[u]=max(len[u],len[v]+1);
	}
}
void dfs3(int u,int f,int upr){
	dep[u]=dep[f]+1;
	if(dep[u]>upr) return;
	ans[u]=tmp[dep[u]];
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs3(v,u,upr);
	}
}
inline bool cmp(int x,int y){return len[x]<len[y];}
void clear(){
	FOR(i,1,n) head[i]=deg[i]=id[i]=ans[i]=len[i]=dep[i]=0;
	FOR(i,1,el) to[i]=nxt[i]=0;
	el=cnt=0;
}
void output(){
	puts("YES");
	FOR(i,1,n) printf("%d ",ans[i]);
	puts("");
	clear();
}
void solve(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);add(v,u);
		deg[u]++;deg[v]++;
	}
	FOR(i,1,n) if(!id[i]){
		x=y=z=e=p=0;
		cnt++;
		dfs(i);
		e/=2;
		if(e>=p){
			FOR(j,1,n) ans[j]=id[j]==id[i];
			return output();
		}
		if(x){
			ans[x]=2;
			for(int j=head[x];j;j=nxt[j]) ans[to[j]]=1;
			return output();
		}
		if(z){
			dfs1(y,0);
			for(int j=head[y];j;j=nxt[j]) if(!ans[to[j]]) ans[to[j]]=1;
			for(int j=head[z];j;j=nxt[j]) if(!ans[to[j]]) ans[to[j]]=1;
			return output();
		}
		if(y){
			dfs2(y,0);
			int a[3];
			a[0]=a[1]=a[2]=0;
			for(int j=head[y];j;j=nxt[j]){
				if(!a[0]) a[0]=to[j];
				else if(!a[1]) a[1]=to[j];
				else a[2]=to[j];
			}
			sort(a,a+3,cmp);
			if(len[a[0]]>=2){
				ans[y]=3;
				tmp[1]=2;tmp[2]=1;
				dfs3(a[0],y,2);
				dfs3(a[1],y,2);
				dfs3(a[2],y,2);
				return output();
			}
			if(len[a[1]]>=3){
				ans[y]=4;
				tmp[1]=2;
				dfs3(a[0],y,1);
				tmp[1]=3;tmp[2]=2;tmp[3]=1;
				dfs3(a[1],y,3);
				dfs3(a[2],y,3);
				return output();
			}
			if(len[a[1]]>=2 && len[a[2]]>=5){
				ans[y]=6;
				tmp[1]=3;
				dfs3(a[0],y,1);
				tmp[1]=4;tmp[2]=2;
				dfs3(a[1],y,2);
				tmp[1]=5;tmp[2]=4;tmp[3]=3;tmp[4]=2;tmp[5]=1;
				dfs3(a[2],y,5);
				return output();
			}
		}
	}
	puts("NO");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}