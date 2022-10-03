#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 4000005
#define MM 4000005
#define ll long long
#define mod 1000000007
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,cnt;
int bits[MM];
int h[MN],nxt[MM],to[MM],w[MM],tot;
inline void ins(int x,int y,int z){/*printf("%d->%d:%d\n",x,y,z);*/nxt[++tot]=h[x];to[tot]=y;w[tot]=z;h[x]=tot;}
int vis[MN],dis[MN],que[MN],l,r;
priority_queue<piii,vector<piii>,greater<piii> >pq;
int id[MN],iid[MN],cs,qwq,ddis[MN];
int val[MN];
int main(){
	scanf("%d%d",&n,&m),cnt=n;
	F(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		bits[i]=bits[i/10]+1;
		int s[8],I=i,t=0;
		while(I)s[++t]=I%10,I/=10;
		int lst=x;
		dF(j,t,1){
			int nxt=j>1?++cnt:y;
			ins(lst,nxt,s[j]);
			lst=nxt;
		}
		lst=y;
		dF(j,t,1){
			int nxt=j>1?++cnt:x;
			ins(lst,nxt,s[j]);
			lst=nxt;
		}
	}
	que[l=r=1]=1,vis[1]=1,dis[1]=0;
	while(l<=r){
		int u=que[l++];
		for(int i=h[u];i;i=nxt[i])if(!vis[to[i]])vis[to[i]]=1,dis[to[i]]=dis[u]+1,que[++r]=to[i];
	}
//	F(i,1,n)printf("dis[%d]=%d\n",i,dis[i]);
	F(i,1,cnt)vis[i]=0;
	pq.push(piii(0,pii(0,1)));
	while(!pq.empty()){
		piii p=pq.top();pq.pop();
		int u=p.se.se,faz=p.se.fi,d=p.fi;
		if(vis[u])continue;
		vis[u]=1,val[u]=(val[faz]*10ll+d%10)%mod;
		if(!qwq)id[u]=cs=1,iid[qwq=1]=u;
		else{
			int uu=iid[qwq];
			if(d>ddis[uu])++cs;
			id[u]=cs,iid[++qwq]=u;
		}
//		printf(" u = %d, fa = %d, w = %d, ddis = %d, id = %d, \tval = %d\n",u,faz,d%10,ddis[u],id[u],val[u]);
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]!=dis[u]+1)continue;
			if(!ddis[v]||ddis[v]>id[u]*10+w[i]){
				ddis[v]=id[u]*10+w[i];
				pq.push(piii(ddis[v],pii(u,v)));
			}
		}
	}
	for(int i=2;i<=n;++i)printf("%d\n",val[i]);
	return 0;
}
/*
12 12
1 2
3 5
5 6
4 6
6 7
7 8
8 9
9 10
10 11
11 12
1 3
2 4
*/