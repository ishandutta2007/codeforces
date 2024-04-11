#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353,d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const char str[]="RLDU";
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
int n,m,tl,atx[maxn],aty[maxn];
vector<vector<int> > a,id,ans;
struct node{
	int x,y,v;
	bool operator<(const node &nd)const{return v<nd.v;}
}tmp[maxn];
const int MAXN=111111,MAXM=1111111;
namespace mf{
	int s,t,tot,el=1,head[MAXN],cur[MAXN],to[MAXM],nxt[MAXM],flow[MAXM],q[MAXN],h,r,dis[MAXN];
	inline void add(int u,int v,int w){
//		printf("add(%d,%d,%d)\n",u,v,w);
		to[++el]=v;nxt[el]=head[u];head[u]=el;flow[el]=w;
		to[++el]=u;nxt[el]=head[v];head[v]=el;flow[el]=0;
	}
	bool bfs(){
		FOR(i,1,tot) dis[i]=-1,cur[i]=head[i];
		dis[s]=0;
		q[h=r=1]=s;
		while(h<=r){
			int u=q[h++];
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				if(dis[v]==-1 && flow[i]){
					dis[v]=dis[u]+1;
					q[++r]=v;
				}
			}
		}
		return ~dis[t];
	}
	int dfs(int u,int minres){
		if(u==t || !minres) return minres;
		int f,rtf=0;
		for(int &i=cur[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]==dis[u]+1 && (f=dfs(v,min(flow[i],minres)))){
				flow[i]-=f;flow[i^1]+=f;
				rtf+=f;minres-=f;
				if(!minres) break;
			}
		}
		return rtf;
	}
	int dinic(){
		int mxf=0;
		while(bfs()) mxf+=dfs(s,1e9);
		return mxf;
	}
	void clear(){
		FOR(i,1,tot) head[i]=cur[i]=0;
		FOR(i,1,el) to[i]=nxt[i]=flow[i]=0;
		s=t=tot=0;
		el=1;
	}
}
namespace cmf1{
	int tot,deg[MAXN],s,t,S,T,mflow;
	inline void add(int u,int v,int l,int r){
//		printf("add(%d,%d,%d,%d)\n",u,v,l,r);
		mf::add(u,v,r-l);
		deg[v]+=l;deg[u]-=l;
		mflow+=l;
	}
	int work(){
		mf::add(t,s,1e9);
		tot+=2;
		S=tot-1;T=tot;
		int sum=0;
		FOR(i,1,tot-2){
			if(deg[i]>0) mf::add(S,i,deg[i]),sum+=deg[i];
			else mf::add(i,T,-deg[i]);
		}
		mf::s=S;
		mf::t=T;
		mf::tot=tot;
		int p=mf::dinic();
//		printf("sum=%d,p=%d\n",sum,p);
		if(p!=sum) return -1;
		else return mflow+sum;
	}
	void clear(){
		FOR(i,1,tot) deg[i]=0;
		S=T=tot=mflow=0; 
		mf::clear();
	}
}
void clear(){
	cmf1::clear();
	tl=0;
	a.clear();
	id.clear();
	ans.clear();
}
void solve(){
	n=read();m=read();
	FOR(i,0,n-1){
		a.PB(vector<int>());
		id.PB(vector<int>());
		ans.PB(vector<int>());
		FOR(j,0,m-1){
			a[i].PB(read());
			tmp[++tl]=(node){i,j,a[i][j]};
			id[i].PB(0);
			ans[i].PB(0);
		}
	}
	sort(tmp+1,tmp+tl+1);
	bool ok=true;
	FOR(i,1,tl){
		int j=i;
		while(j<tl && tmp[i].v==tmp[j+1].v) j++;
//		printf("work %d\n",tmp[i].v);
		int S=j-i+2,T=S+1;
		cmf1::s=S;
		cmf1::tot=cmf1::t=T;
		FOR(k,i,j){
			int x=tmp[k].x,y=tmp[k].y;
			id[x][y]=k-i+1;
			atx[id[x][y]]=x,aty[id[x][y]]=y;
			bool flag=true;
			FOR(l,0,3){
				int tx=x+d[l][0],ty=y+d[l][1];
				if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
				if(a[tx][ty]<a[x][y]) flag=false,ans[x][y]=l;
				else if(a[tx][ty]==a[x][y] && id[tx][ty]){
					if((x+y)&1) cmf1::add(id[x][y],id[tx][ty],0,1);
					else cmf1::add(id[tx][ty],id[x][y],0,1);
				}
			}
			if((x+y)&1) cmf1::add(S,id[x][y],flag,1);
			else cmf1::add(id[x][y],T,flag,1);
		}
		if(cmf1::work()==-1){puts("NO");ok=false;break;}
		FOR(k,i,j){
			int x=tmp[k].x,y=tmp[k].y;
			if(!((x+y)&1)) continue;
			int u=id[x][y];
			for(int l=mf::head[u];l;l=mf::nxt[l]){
				int v=mf::to[l];
				if(v<S && mf::flow[l^1]){
					int tx=atx[v],ty=aty[v];
					if(tx!=x) ans[x][y]=x+1==tx?2:3;
					else ans[x][y]=y+1==ty?0:1;
					ans[tx][ty]=ans[x][y]^1;
					break;
				}
			}
		}
		cmf1::clear();
		i=j;
	}
	if(ok){
		puts("YES");
		FOR(i,0,n-1){
			FOR(j,0,m-1){
				int x=i+d[ans[i][j]][0],y=j+d[ans[i][j]][1];
				if(a[i][j]==a[x][y]) printf("%d ",(a[i][j]+((i+j)&1))/2);
				else printf("%d ",a[i][j]-a[x][y]);
			}
			puts("");
		}
		FOR(i,0,n-1){
			FOR(j,0,m-1) printf("%c ",str[ans[i][j]]);
			puts("");
		}
	}
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}