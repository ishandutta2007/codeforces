#include<bits/stdc++.h>
#define M 998244353
#define pr std::pair<int,int>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct Tsh{int c,q;}S[200010];
int rt;
int st[200010],key[200010],b[200010],lazy[200010];
int tag[200010],ans[200010],ls[200010],rs[200010],siz[200010];
void Upd(int x,int o){if(x)b[x]-=o,lazy[x]+=o;}
void Uans(int x,int o){tag[x]+=o,ans[x]+=o;}
void down(int x){
	if(!x)return;
	if(lazy[x])Upd(ls[x],lazy[x]),Upd(rs[x],lazy[x]),lazy[x]=0;
	if(tag[x])Uans(ls[x],tag[x]),Uans(rs[x],tag[x]),tag[x]=0;
}
void upd(int x){if(x)siz[x]=siz[ls[x]]+siz[rs[x]]+1;}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(key[x]<key[y]){down(x);rs[x]=merge(rs[x],y);return upd(x),x;}
	else{down(y);ls[y]=merge(x,ls[y]);return upd(y),y;}
}
pr split(int x,int w){
	if(!x)return{0,0};
	down(x);
	if(b[x]<=w){pr r=split(rs[x],w);rs[x]=r.first;upd(x);return{x,r.second};}
	else{pr l=split(ls[x],w);ls[x]=l.second;upd(x);return{l.first,x};}
}
void dfs(int x,int&s){
	if(!x)return;
	down(x);
	int L=ls[x],R=rs[x];
	ls[x]=rs[x]=0;siz[x]=1;
	if(~s){
		pr A=split(s,b[x]);
		s=merge(A.first,merge(x,A.second));
	}
	dfs(L,s),dfs(R,s);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)S[i].c=gi(),S[i].q=gi();
	int m=gi();
	key[1]=rand()%(M-1)+1;
	for(int i=2;i<=m;++i)key[i]=key[i-1]*114514ll%M;
	for(int i=1;i<=m;++i)b[i]=gi(),st[i]=i;
	std::sort(st+1,st+m+1,[&](int i,int j){return b[i]<b[j];});
	for(int i=1;i<=m;++i)rt=merge(rt,st[i]);
	std::sort(S+1,S+n+1,[](Tsh a,Tsh b){return a.q==b.q?a.c<b.c:a.q>b.q;});
	for(int i=1;i<=n;++i){
		int ci=S[i].c;
		pr _A=split(rt,ci-1),_B=split(_A.second,ci*2-1);
		int A=_A.first,B=_B.first,C=_B.second;
		Upd(B,ci);Uans(B,1);Upd(C,ci);Uans(C,1);
		if(siz[A]<siz[B])std::swap(A,B);
		dfs(B,A);
		rt=merge(A,C);
	}
	int s=-1;dfs(rt,s);
	for(int i=1;i<=m;++i)printf("%d ",ans[i]);
	return 0;
}