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
#define M 1000020
#define ls first
#define rs second
multiset<int>S;
set<pii >seg;
int n,t[M],p[M],m,ans[M],f[M],kd[M],res,now;
inline int fd(int x){return f[x]==x?x:f[x]=fd(f[x]);}
vector<int>pos[M];
#define IT set<pii >::iterator
inline void del(IT it){
	IT l=it,r=it; l--,r++;
	S.erase(S.find((*it).ls-(*l).rs-1));
	S.erase(S.find((*r).ls-(*it).rs-1));
	S.insert((*r).ls-(*l).rs-1);
	seg.erase(it);
}
inline void ins(int ls,int rs){
	seg.insert(mp(ls,rs)); IT it=seg.find(mp(ls,rs)),l=it,r=it; l--,r++;
	S.insert(ls-(*l).rs-1),S.insert((*r).ls-(*it).rs-1),S.erase(S.find((*r).ls-(*l).rs-1));
	if(!kd[ls]) return; int dnl=ls,dnr=rs;
	dnl=(kd[(*l).ls]!=0)?((*l).rs+1):(((*l).rs+ls+1)>>1);
	dnr=(kd[(*r).rs]!=0)?((*r).ls-1):(((*r).ls+rs-1)>>1);
	for(int i=fd(dnl);i<=dnr;i=fd(dnl)) ans[i]=now,f[i]=i+1;
	// printf("go1 "); debug(dnl)sp,debug(dnr)el;
}
inline IT cov(int x){IT it=seg.lower_bound(mp(x+1,-1));--it; return it;}
inline void mdf(int x){
	// debug(x)sp,debug(now)el;
	kd[x]=1;
	if(kd[x-1]==0||kd[x+1]==0){
		IT it=cov(x); int l=(*it).ls,r=(*it).rs; del(it);
		if(l+1<x) ins(l,x-1); if(r-1>x) ins(x+1,r);
	}
	if(kd[x-1]==1||kd[x+1]==1){
		int l=x,r=x; IT it;
		// debug(l)sp,debug(r)el;
		if(kd[x-1]==1){
			if(x-1>1&&kd[x-2]==1) it=cov(x-1),l=(*it).ls,del(it);
			else l=x-1;
		}
		// debug(l)sp,debug(r)el;
		if(kd[x+1]==1){
			if(x+1<n+2&&kd[x+2]==1) it=cov(x+1),r=(*it).rs,del(it);
			else r=x+1;
		}
		// debug(l)sp,debug(r)el;
		ins(l,r);
	}
	else{
		IT r=seg.upper_bound(mp(x,x)),l; l=r,l--; int tl=(*l).rs,tr=(*r).ls;
		if(kd[tl]==0&&kd[tr]==0) return;
		if(kd[tl]==-1&&kd[tr]==-1) return;
		int dnl=2,dnr=1;
		if(kd[tl]==1&&kd[tr]==1) dnl=tl+1,dnr=tr-1;
		if(kd[tl]==0&&kd[tr]==1) dnl=((tl+tr+1)>>1),dnr=tr-1;
		if(kd[tl]==1&&kd[tr]==0) dnl=tl+1,dnr=((tl+tr-1)>>1);
		for(int i=fd(dnl);i<=dnr;i=fd(dnl)) ans[i]=now,f[i]=i+1;
		// printf("go2 "); debug(tl-1)sp,debug(tr-1)el,debug(dnl)sp,debug(dnr)el;
	}
}
inline void solve(int x){
	now=t[x];
	for(int j=0,TP=pos[x].size();j<TP;j++) mdf(pos[x][j]);//,fgx;
	res=max(res,((*(--S.end())+1))>>1);
}
int main(){
	n=read(),kd[0]=kd[n+3]=-1;
	for(int i=2;i<=n+1;i++) p[i]=t[i-1]=read();
	p[1]=p[2],p[n+2]=p[n+1],f[n+3]=n+3;
	sort(t+1,t+n+1),m=unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n+2;i++) pos[p[i]=lower_bound(t+1,t+m+1,p[i])-t].pb(i),f[i]=i;
	// for(int i=1;i<=n+2;i++) debug(i)sp,debug(p[i])el;
	seg.insert(mp(1,n+2)),f[1]=2;
	seg.insert(mp(0,0)),seg.insert(mp(n+3,n+3));
	S.insert(0),S.insert(0),S.insert(0);
	for(int i=1;i<=m;i++) solve(i); ans[2]=t[p[2]],ans[n+1]=t[p[n+1]];
	printf("%d\n",res);
	for(int i=2;i<=n+1;i++) printf("%d%c",ans[i],i<=n?' ':'\n');
	return 0;
}