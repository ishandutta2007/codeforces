#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define uint unsigned int
#define ULL unsigned long long
#define LDB long double 
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
namespace IO{
	const int BS=(1<<23)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(LL x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	inline LL read(){
		LL nm=0; bool fh=true; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define M 200200
int n,m,fs[M],nt[M<<1],to[M<<1],tmp,dfn[M],sz[M];
LL dis[M],len[M<<1],val[M];
int nd[M],hd,tl,q[M],c[M],cnt;
inline void link(int x,int y,int d){nt[tmp]=fs[x],fs[x]=tmp,to[tmp]=y,len[tmp++]=d;}
inline void BFS(int S){
	hd=tl=1,memset(dis,0x3f,sizeof(dis)),dis[S]=0,q[tl++]=S;
	for(int x=q[hd];hd<tl;x=q[++hd]) for(int i=fs[x];i!=-1;i=nt[i])
		if(dis[to[i]]>dis[x]+len[i]) dis[to[i]]=dis[x]+len[i],q[tl++]=to[i];
}
inline void dfs(int x,int last=0){
	dfn[x]=++cnt,sz[x]=1;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last)
		dfs(to[i],x),sz[x]+=sz[to[i]];
}
inline void ins(int x,int kd=1){for(int k=dfn[x];k<=n;k+=(k&-k))c[k]+=kd;}
inline int qry(int x,int tt=0){
	for(int k=dfn[x]+sz[x]-1;k;k-=(k&-k)) tt+=c[k];
	for(int k=dfn[x]-1;k;k-=(k&-k)) tt-=c[k]; return tt;
}
inline bool cmp(int x,int y){return val[x]<val[y];}
int main(){
	n=read(),memset(fs,-1,sizeof(fs));
	for(int i=1,x,y,d;i<n;i++) x=read(),y=read(),d=read(),link(x,y,d),link(y,x,d);
	BFS(1); int nd1=1,nd2=1,root=1;
	for(int i=2;i<=n;i++) if(dis[i]>dis[nd1]) nd1=i; BFS(nd1);
	for(int i=1;i<=n;i++) val[i]=max(val[i],dis[i]);
	for(int i=2;i<=n;i++) if(dis[i]>dis[nd2]) nd2=i; BFS(nd2);
	for(int i=1;i<=n;i++) val[i]=max(val[i],dis[i]),nd[i]=i;
	sort(nd+1,nd+n+1,cmp),root=nd[1],dfs(root);
	for(int Cas=read();Cas;--Cas){
		LL lim=read(); int rs=1,ans=1;
		for(int i=1;i<=n;i++){
			int x=nd[i];
			while(rs<=n&&val[nd[rs]]<=val[x]+lim) ins(nd[rs++]);
			ans=max(ans,qry(x)),ins(x,-1);
		} printf("%d\n",ans);
	}
	return 0;
}