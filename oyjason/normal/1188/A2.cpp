#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" -------------------------------------------------------- "<<endl
#define LL long long
#define DB double
#define LDB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline int read(){
	int nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 200020
int n,m,fs[M],nt[M],to[M],len[M],d[M],RT,lev[M],ot[M],bo[M],u[M],v[M],w[M],tot,tmp;
inline void link(int x,int y,int k){nt[tmp]=fs[x],fs[x]=tmp,to[tmp]=y,len[tmp++]=k,d[y]++;}
inline void ins(int x,int y,int k){u[++tot]=x,v[tot]=y,w[tot]=k;}
inline void paint(int lv,int x,int val){ins(lv,ot[x],val/2),ins(lv,bo[x],val/2),ins(ot[x],bo[x],-(val/2));}
inline void dfs2(int x,int fa,int val){
	if(d[x]==1){paint(x,x,val);return;}
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=fa) ot[to[i]]=ot[x],dfs2(to[i],x,len[i]);
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=fa&&lev[to[i]]==lev[x]){
		paint(lev[x],to[i],-val),paint(lev[x],x,val);break;
	}
}
inline void dfs1(int x,int last){
	if(d[x]==1){lev[x]=x;return;} int fst=-1,snd=-1;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last){
		dfs1(to[i],x);
		if(fst==-1) fst=lev[to[i]];
		else if(snd==-1) snd=lev[to[i]];
	}
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last){
		if(lev[to[i]]^fst) bo[to[i]]=fst;
		else bo[to[i]]=snd;
	}
	lev[x]=fst;
	if(!last){
		int trd=-1;
		for(int i=fs[x];i!=-1;i=nt[i]) if(lev[to[i]]!=fst&&lev[to[i]]!=snd){trd=lev[to[i]];break;}
		for(int i=fs[x];i!=-1;i=nt[i]){
			if(fst!=lev[to[i]]&&fst!=bo[to[i]]) ot[to[i]]=fst;
			else if(snd!=lev[to[i]]&&snd!=bo[to[i]]) ot[to[i]]=snd;
			else if(trd!=lev[to[i]]&&trd!=bo[to[i]]) ot[to[i]]=trd;
			dfs2(to[i],x,len[i]);
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(fs,-1,sizeof(fs)),n=read();
	for(int i=1,x,y,k;i<n;i++) x=read(),y=read(),k=read(),link(x,y,k),link(y,x,k);
	for(int i=1;i<=n;i++) if(d[i]==2){puts("NO");return 0;} puts("YES");
	if(n==2){printf("1\n1 2 %d\n",len[0]);return 0;}
	for(int i=1;i<=n;i++) if(d[i]>1){RT=i;break;}
	dfs1(RT,0),printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d %d %d\n",u[i],v[i],w[i]);
	return 0;
}