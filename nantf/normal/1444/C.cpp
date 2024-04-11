#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,k,c[maxn],el1,head1[maxn],to1[maxn],nxt1[maxn],el2,head2[maxn],to2[maxn],nxt2[maxn],col[maxn],dsc[maxn],dl;
int cnt,tot,fa[maxn*2],tmp[maxn],tl;
ll ans;
bool vis[maxn],flag[maxn],used[maxn],hhh[maxn];
vector<int> v[maxn];
vector<PII> wtf[maxn];
inline int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
inline void unite(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x==y) return;
	fa[x]=y;
}
inline bool check(int x,int y){
	x=getfa(x);y=getfa(y);
	return x==y;
}
inline void add1(int u,int v){
	to1[++el1]=v;nxt1[el1]=head1[u];head1[u]=el1;
}
inline void add2(int u,int v){
	to2[++el2]=v;nxt2[el2]=head2[u];head2[u]=el2;
}
void dfs(int u){
	vis[u]=true;
	for(int i=head1[u];i;i=nxt1[i]){
		int v=to1[i];
		if(vis[v]){
			if(col[v]!=(col[u]^1)) flag[c[u]]=true;
			continue;
		}
		col[v]=col[u]^1;
		dfs(v);
	}
}
int main(){
	n=read();m=read();k=read();
	FOR(i,1,n) c[i]=read(),v[c[i]].PB(i);
	FOR(i,1,m){
		int u=read(),v=read();
		if(c[u]==c[v]) add1(u,v),add1(v,u);
		else add2(u,v),add2(v,u);
	}
	FOR(i,1,k){
		FOR(j,0,(int)v[i].size()-1){
			int u=v[i][j];
			if(!vis[u]) col[u]=cnt+=2,dfs(u);
		}
		if(!flag[i]){
//			printf("work %d\n",i);
			int ttot=tot;
			tl=0;
			FOR(j,0,(int)v[i].size()-1){
				int u=v[i][j];
				for(int k=head2[u];k;k=nxt2[k]){
					int v=to2[k];
					if(c[v]<c[u] && !flag[c[v]]){
						if(!hhh[c[v]]) hhh[c[v]]=true,tmp[++tl]=c[v];
						wtf[c[v]].PB(MP(col[u],col[v]));
						wtf[c[v]].PB(MP(col[u]^1,col[v]^1));
					}
				}
			}
			FOR(j,1,tl){
				int t=tmp[j];
//				dcnt=1;
//				dsc.clear();
//				printf("with %d\n",t);
				dl=0;
				FOR(k,0,(int)wtf[t].size()-1){
					PII &p=wtf[t][k];
//					printf("%d %d\n",p.first,p.second);
//					if(!dsc[p.first]) dsc[p.first]=++dcnt;
//					if(!dsc[p.second]) dsc[p.second]=++dcnt;
//					p.first=dsc[p.first];
//					p.second=dsc[p.second];
					dsc[++dl]=p.first;
					dsc[++dl]=p.second;
				}
				sort(dsc+1,dsc+dl+1);dl=unique(dsc+1,dsc+dl+1)-dsc-1;
				FOR(k,2,dl+1) fa[k]=k;
				FOR(k,0,(int)wtf[t].size()-1){
					PII p=wtf[t][k];
					int u=lower_bound(dsc+1,dsc+dl+1,p.first)-dsc+1;
					int v=lower_bound(dsc+1,dsc+dl+1,p.second)-dsc+1;
//					printf("(%d,%d) become (%d,%d)\n",p.first,p.second,u,v);
					unite(u,v^1);
					unite(u^1,v);
				}
				bool x=false;
				assert(dl%2==0);
				FOR(k,1,dl/2) if(check(k*2,k*2+1)) x=true;
				if(x) ttot--;//,puts("not ok");
			}
			FOR(j,0,(int)v[i].size()-1){
				int u=v[i][j];
				for(int k=head2[u];k;k=nxt2[k]){
					int v=to2[k];
					if(c[v]<c[u] && !flag[c[v]]){
						wtf[c[v]].clear();
						hhh[c[v]]=false;
					}
				}
			}
			ans+=ttot;
			tot++;
		}
	}
	printf("%lld\n",ans);
}
/*
8 8 2
1 1 1 1 2 2 2 2
1 2
3 4
5 6
7 8
2 5
2 7
4 7
4 6

6 8 3
1 1 2 2 3 3
1 2
2 4
4 1
1 5
5 6
6 2
3 6
4 5
*/