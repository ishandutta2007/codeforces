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
#define pli pair<LL,int>
#define mp make_pair
#define pb push_back
#define nd second
#define ds first
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 100200
#define pll pair<LL,LL>
#define ls first
#define rs second
int n,m,fs[M],nt[M],to[M],tmp,len[M],ed[M],f[M],ti[M],nd[M];
LL dis[M],h[M*22];
pll p[M*22],Q[M*42],D[M*22]; int mq,md,ans; LL res=-1;
vector<int>t[M];
set<int>s[M]; int id[M];
priority_queue<LL>H;
inline void link(int x,int y,int d){nt[tmp]=fs[x],fs[x]=tmp,to[tmp]=y,len[tmp++]=d,ed[x]=y;}
inline int fd(int x){return x==f[x]?x:f[x]=fd(f[x]);}
#define IT set<int>::iterator
inline void DP(int x){
	int mxs=0;
	for(int i=fs[x];i!=-1;i=nt[i]){
		dis[to[i]]=dis[x]+len[i],DP(to[i]);
		if(s[id[to[i]]].size()>s[id[mxs]].size()) mxs=to[i];
	} id[x]=(mxs>0?id[mxs]:x);
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=mxs){
		int y=to[i];
		for(IT it=s[id[y]].begin();it!=s[id[y]].end();it++){
			LL pr=0,sf=0,k=(*it); s[id[x]].insert(k);
			IT w=s[id[x]].find(k);
			if(w!=s[id[x]].begin()) w--,pr=(*w),++w;
			w++; if(w!=s[id[x]].end()) sf=(*w); w--;
			if(pr>0&&sf>0&&fd(nd[pr])!=fd(nd[sf])) D[++md]=mp(ti[pr]+dis[x],ti[sf]+dis[x]);
			if(pr>0&&fd(nd[pr])!=fd(nd[k])) Q[++mq]=mp(ti[pr]+dis[x],ti[k]+dis[x]);
			if(sf>0&&fd(nd[k])!=fd(nd[sf])) Q[++mq]=mp(ti[k]+dis[x],ti[sf]+dis[x]);
		} s[id[y]].clear();
	}
	if(!s[id[x]].empty()){
		IT it=s[id[x]].begin(); int k=(*it);
		if(fd(nd[k])!=ed[x]) Q[++mq]=mp(0,ti[k]+dis[x]);
	}
	for(int i=0,TP=t[x].size();i<TP;i++) s[id[x]].insert(t[x][i]);
	for(int i=fs[x];i!=-1;i=nt[i]) f[to[i]]=x;
}
int main(){
	// for(int Cas=read();Cas;--Cas) puts(solve()?"YES":"NO");
	n=read(),m=read(),memset(fs,-1,sizeof(fs));
	for(int x,y,d,i=1;i<n;i++) x=read(),y=read(),d=read(),link(x,y,d);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) nd[i]=read(),ti[i]=read(),t[nd[i]].pb(i);
	DP(1),sort(Q+1,Q+mq+1),sort(D+1,D+md+1),m=0;
	for(int i=1,bs=1;i<=mq;i++){
		while(bs<=md&&Q[i]==D[bs]) ++bs,++i;
		if(i<=mq) p[++m]=mp(Q[i].ls+1,Q[i].rs);
	} LL now=-1; int bs=1;
	// fgx;
	// for(int i=1;i<=m;i++) printf("[ %lld %lld ]\n",p[i].ls,p[i].rs);
	
	while(!H.empty()||bs<=m){
		if(H.empty()) now=max(now,p[bs].ls);
		else if(-H.top()<now){res=-H.top();break;}
		while(bs<=m&&p[bs].ls<=now) H.push(-p[bs++].rs);
		now++,h[++ans]=-H.top(),H.pop();
	} sort(h+1,h+ans+1);
	while(res>0&&h[ans]>=res) --ans;
	printf("%lld %d\n",res,ans);
	return 0;
}