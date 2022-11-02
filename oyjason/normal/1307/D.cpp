#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 400100
#define mod 1000000007
int n,m,K;
int fs[M],nt[M],to[M],tmp;
int ds1[M],ds2[M],q[M],hd,tl;
int nd[M];
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
inline void BFS(int s,int *dis){
	memset(dis,-1,sizeof(int)*(M-1)),hd=tl=0,q[tl++]=s,dis[s]=0;
	for(int x=q[hd];hd<tl;x=q[++hd])
		for(int i=fs[x];i!=-1;i=nt[i]) if(dis[to[i]]==-1)
			dis[to[i]]=dis[x]+1,q[tl++]=to[i];
}
pii p[M]; int ans;
int main(){
	n=read(),m=read(),K=read(),memset(fs,-1,sizeof(fs));
	for(int i=1;i<=K;i++) nd[i]=read();
	for(int i=1,x,y;i<=m;i++) x=read(),y=read(),link(x,y),link(y,x);
	BFS(1,ds1),BFS(n,ds2);
	for(int i=1;i<=K;i++) p[i]=mp(ds1[nd[i]],ds2[nd[i]]);
	sort(p+1,p+K+1),ans=0;
	for(int mx=p[K].second,i=K-1;i>=1;mx=max(mx,p[i].second),--i)
		ans=max(ans,mx+p[i].first+1);
	ans=min(ans,ds1[n]),printf("%d\n",ans);
	return 0;
}