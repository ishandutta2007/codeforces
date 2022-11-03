#include<bits/stdc++.h>
#define il inline
#define vd void
#define pr std::pair<int,int>
#define mp std::make_pair
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int rnd[300010],w[300010],lz[300010],ls[300010],rs[300010];
il vd upd(int x,int d){if(x)w[x]+=d,lz[x]+=d;}
il vd down(int x){if(lz[x])upd(ls[x],lz[x]),upd(rs[x],lz[x]),lz[x]=0;}
il pr split(int x,int key){
	if(!x)return mp(0,0);
	down(x);
	if(w[x]<=key){
		pr p=split(rs[x],key);
		rs[x]=p.first;
		return mp(x,p.second);
	}else{
		pr p=split(ls[x],key);
		ls[x]=p.second;
		return mp(p.first,x);
	}
}
il int merge(int x,int y){
	if(!x||!y)return x|y;
	if(rnd[x]<rnd[y]){down(x),rs[x]=merge(rs[x],y);return x;}
	else{down(y),ls[y]=merge(x,ls[y]);return y;}
}
il int get(int x,int*son){while(son[x])down(x),x=son[x];return x;}
int ans=0;
il vd dfs(int x){
	if(!x)return;
	dfs(ls[x]),++ans,dfs(rs[x]);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),l,r,rt=1;
	int seed=23333,mo=993244853;
	for(int i=1;i<=n;++i)rnd[i]=seed=1ll*seed*1234ll%mo;
	l=gi(),r=gi();
	w[1]=l;
	for(int i=2;i<=n;++i){
		l=gi(),r=gi();
		pr A=split(rt,l-1),B=split(A.second,r-1);
		w[i]=l,A.first=merge(A.first,i);
		upd(B.first,1);
		if(B.second){
			int x=B.second,lst=0;while(ls[x])down(x),lst=x,x=ls[x];
			if(lst)ls[lst]=rs[x];else B.second=rs[x];
		}
		rt=merge(A.first,merge(B.first,B.second));
	}
	ans=0,dfs(rt);
	printf("%d\n",ans);
	return 0;
}