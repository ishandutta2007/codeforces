#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
namespace IO{
	const int BS=(1<<23)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(int x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	inline LL read(){
		LL nm=0; bool fh=true; char cw=Getchar();
		for(;!isdigit(cw);cw=Getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=Getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define M 600020
int n,m,S[M],top,tmp,fs[M],nt[M<<1],to[M<<1],u[M],v[M],d[M],dep[M],ok[M],fa[M];
int q[M],hd,tl,TM,las[M],w[M];
inline bool solve0(int x=1){
	while(x<=n&&d[x]) ++x; if(x>n) return false;
	for(int i=1;i<=n;i++) ok[i]=1; ok[x]=0;
	for(int i=1;i<=n;i++) if(i^x) S[++top]=i; return true;
}

inline void build(int x){
	dep[x]=1,hd=tl=0,q[tl++]=x;
	for(x=q[hd];hd<tl;x=q[++hd]) for(int i=fs[x];(d[x]>1||hd==0)&&i!=-1;i=nt[i]) if(!dep[to[i]])
		dep[to[i]]=dep[x]+1,fa[to[i]]=x,q[tl++]=to[i];
}
inline void build0(int x,int last=0){
	dep[x]=dep[fa[x]=last]+1;
	for(int i=fs[x];i!=-1;i=nt[i]) if(!dep[to[i]]) build0(to[i],x);
}
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}

inline bool solve2(){
	for(int x=1;x<=n;x++) dep[x]=fa[x]=0,fs[x]=-1; tmp=0;
	for(int i=1;i<=m;i++) if(d[u[i]]==2&&d[v[i]]==2) w[u[i]]++,w[v[i]]++,link(u[i],v[i]),link(v[i],u[i]);
	for(int i=1;i<=n;ok[i]=1,i++) if(d[i]==2&&!dep[i]) build0(i); int ans=n+1,k1=0,k2=0;
	for(int i=1;i<=m;i++) if(d[u[i]]==2&&d[v[i]]==2){
		int x=u[i],y=v[i]; if(dep[x]<dep[y]) swap(x,y); if(fa[x]==y||(dep[x]==n&&dep[y]==1)) continue;
		if(dep[x]-dep[y]<ans) ans=dep[x]-dep[y],k1=x,k2=y;
	} if(ans==n+1) return false;
	while(ok[k2]) ok[k1]=0,k1=fa[k1];
	for(int k=1;k<=n;k++) if(ok[k]) S[++top]=k; return true;
}

//  ---------------------------------------------------------------------

inline bool solve121(){
	for(int i=1;i<=n;fs[i]=-1,fa[i]=0,dep[i]=0,w[i]=0,i++); tmp=0;
	for(int i=1;i<=m;i++) link(u[i],v[i]),link(v[i],u[i]);
	for(int i=1;i<=n;i++) ok[i]=1,dep[i]=fa[i]=0;
	for(int i=1;i<=n;i++) if(d[i]==1){
		build(i);
		for(int y=i+1;y<=n;y++) if(d[y]==1&&dep[y]>1&&dep[y]<n){
			while(ok[i]) ok[y]=0,y=fa[y];
			for(int k=1;k<=n;k++) if(ok[k]) S[++top]=k;
			return true;
		} return false;
	} return false;
}

int f[M];
inline int fd(int x){return x==f[x]?x:f[x]=fd(f[x]);}
inline bool solvebtf(){
	int abt=0,K=0,t1,t2;
	for(int x=1;x<=n;f[x]=x,x++) w[x]=0,ok[x]=1,dep[x]=fa[x]=0,fs[x]=-1,K+=(d[x]==1); tmp=0; if(!K) return false;
	for(int i=1;i<=m;i++){
		if(d[u[i]]==2&&d[v[i]]==2) link(u[i],v[i]),link(v[i],u[i]),f[fd(u[i])]=fd(v[i]);
		abt+=(d[u[i]]+d[v[i]]==3);
	} if(abt==4&&m==n+1&&K==1) return false;
	for(int i=1;i<=m;i++) if(d[u[i]]+d[v[i]]==3){if(d[u[i]]>d[v[i]]) swap(u[i],v[i]);link(u[i],v[i]);} K=-1;
	for(int x=1;x<=n;x++,++TM) if(d[x]==1){
		int CNT=0;
		for(int i=fs[x];i!=-1;las[fd(to[i])]=TM,i=nt[i]){
			if(las[fd(to[i])]<TM) las[fd(to[i])]=TM,w[fd(to[i])]=0;
			if((++w[fd(to[i])])!=2) continue; ++CNT,t1=t2,t2=to[i];
		} if(CNT<2) continue; K=x; break;
	} if(K==-1) return false; build(t1),build(t2),ok[K]=0;
	for(int x=1;x<=n;x++) w[x]=0; int ans1=n+1,ans2=n+1,k1,k2;
	for(int i=fs[K];i!=-1;i=nt[i]) w[to[i]]=1;
	for(int i=fs[K];i!=-1;i=nt[i]){
		int x=to[i];
		if(fd(x)==fd(t1)&&dep[x]>1&&dep[x]<ans1) k1=x,ans1=dep[x];
		if(fd(x)==fd(t2)&&dep[x]>1&&dep[x]<ans2) k2=x,ans2=dep[x];
	}
	while(k1) ok[k1]=0,k1=fa[k1]; while(k2) ok[k2]=0,k2=fa[k2];
	for(int x=1;x<=n;x++) if(ok[x]) S[++top]=x; return true;
}

inline bool solve(){
	n=read(),m=read(),top=tmp=0;
	for(int i=1;i<=n;i++) fs[i]=-1,d[i]=0,dep[i]=0,fa[i]=0,w[i]=0,ok[i]=1;
	for(int i=1;i<=m;i++) (++d[u[i]=read()])%=3,(++d[v[i]=read()])%=3;
	if(n==1) return false; if(solve0()) return true;
	if(solve2()) return true;
	if(solve121()) return true; 
	if(solvebtf()) return true; return false;
}

int main(){
	for(int Cas=read();Cas;--Cas){
		if(!solve()){Putchar('N'),Putchar('o'),Putchar('\n');continue;}
		Putchar('Y'),Putchar('e'),Putchar('s'),Putchar('\n');
		write(top),Putchar('\n');
		for(int i=1;i<=top;i++) write(S[i]),Putchar(i<top?' ':'\n');
		
		continue;

		for(int i=1;i<=top;i++) ok[S[i]]=-Cas;
		for(int i=1;i<=m;i++) if(ok[u[i]]>=0&&ok[v[i]]>=0) --d[u[i]],--d[v[i]];
		for(int i=1;i<=n;i++) if(abs(d[i])%3>0&&ok[i]>=0){
			assert(false);
			printf("n = %d  m = %d\n",n,m);
			for(int i=1;i<=m;i++) printf("%d %d\n",u[i],v[i]);
			assert(false);return 0;
		}
	} flush(); return 0;
}