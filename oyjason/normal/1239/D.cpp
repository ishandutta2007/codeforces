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
inline int read(){
	int nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
#define M 1200020
int n,m,dfn[M],low[M],S[M],top,be[M],typ[M],cnt,tmp;
int fs[M],nt[M],to[M];
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
inline bool dfs(int x){
	++cnt,S[++top]=x,dfn[x]=low[x]=cnt;
	for(int i=fs[x];i!=-1;i=nt[i]){
		if(!dfn[to[i]]){if(dfs(to[i]))return true;}
		low[x]=min(low[x],low[to[i]]);
	} if(low[x]<dfn[x]) return false;
	if(top==n&&S[1]==x) return false; int tot=0;
	while(typ[x]==0) typ[S[top--]]=1,++tot;
	printf("Yes\n%d %d\n",tot,n-tot);
	for(int i=1;i<=n;i++) if(typ[i]==1) printf("%d ",i); puts("");
	for(int i=1;i<=n;i++) if(typ[i]==0) printf("%d ",i); puts("");
	return true;
}
int main(){
	for(int Cas=read();Cas;--Cas){
		n=read(),m=read(),tmp=0,cnt=0;
		memset(fs,-1,sizeof(int)*(n+4)),memset(typ,0,sizeof(int)*(n+4));
		memset(dfn,0,sizeof(int)*(n+4)),top=0;
		for(int x,y,i=1;i<=m;i++){x=read(),y=read();if(x^y) link(x,y);} int ok=0;
		for(int i=1;i<=n&&ok==0;i++) if(!dfn[i]) ok|=dfs(i);
		if(!ok) puts("No");
	}
	return 0;
}