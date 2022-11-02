#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ----------------------------------- "<<endl
#define LL long long
#define DB long double
#define LDB long double
#define ULL unsigned long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define rint register int
using namespace std;
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
	inline int read(){
		int nm=0; bool fh=true; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define INF 1070000000
#define M 160
int n,m,fs[M],nt[M],to[M],u[M],v[M],w[M],ans=-1;
bool F[32][M][M],G[M],H[M],tar[M];
inline void rw(int k,int x,int y){
	if(k>=30||F[k][x][y]) return; F[k][x][y]=true;
	for(int st=1;st<=n;++st) if(F[k][st][x]) rw(k+1,st,y);
	for(int ed=1;ed<=n;++ed) if(F[k][y][ed]) rw(k+1,x,ed);
}
inline void solve(int now,int nxt){
	if(G[n]){ans=now;return;} memcpy(H,G,sizeof(H));
	for(int tms=1;tms<n&&now+tms<=nxt;tms++){
		memset(tar,false,sizeof(tar));
		for(int i=1;i<=m&&w[i]<=now;i++) tar[v[i]]|=H[u[i]];
		memcpy(H,tar,sizeof(H));
		if(H[n]){ans=tms+now;return;}
	} if(nxt==INF) return; memset(tar,false,sizeof(tar));
	for(int k=0,rem=nxt-now;rem;rem>>=1,++k) if(rem&1){
		memset(tar,false,sizeof(tar));
		for(int x=1;x<=n;x++) if(G[x]) for(int y=1;y<=n;y++)
			tar[y]|=(G[x]&F[k][x][y]); memcpy(G,tar,sizeof(G));
	}
}
int main(){
	n=read(),m=read(),G[1]=true;
	for(int i=1;i<=m;i++) u[i]=read(),v[i]=read(),w[i]=read();
	u[++m]=n,v[m]=n,w[m]=0,memset(F,false,sizeof(F));
	for(int tms=1;tms<=m;tms++) for(int i=1;i<m;i++) if(w[i]>w[i+1])
		swap(u[i],u[i+1]),swap(v[i],v[i+1]),swap(w[i],w[i+1]);
	if(n==1){puts("0");return 0;} w[m+1]=INF;
	if(w[1]!=0){puts("Impossible");return 0;}
	for(int i=1;i<=m&&ans==-1;i++){
		rw(0,u[i],v[i]);
		if(w[i+1]>w[i]) solve(w[i],w[i+1]);
	}
	if(ans==-1){puts("Impossible");return 0;}
	printf("%d\n",ans); return 0;
}