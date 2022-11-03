// ioiakyyb
#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
#define pr std::pair<int,int>
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int w[100010];
int W[400010],lz[400010],lz2[400010];
#define mid ((l+r)>>1)
il vd upd(int x,int k){W[x]=lz[x]=k;lz2[x]=0;}
il vd upd2(int x){W[x]=-W[x],lz2[x]^=1;}
il vd down(int x){
	if(lz[x])upd(x<<1,lz[x]),upd(x<<1|1,lz[x]),lz[x]=0;
	if(lz2[x])upd2(x<<1),upd2(x<<1|1),lz2[x]=0;
}
il vd update(int x,int l,int r,const int&L,const int&R,const int&k){
	if(L<=l&&r<=R)return upd(x,k);
	down(x);
	if(L<=mid)update(x<<1,l,mid,L,R,k);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,k);
}
il vd update2(int x,int l,int r,const int&L,const int&R){
	if(L<=l&&r<=R)return upd2(x);
	down(x);
	if(L<=mid)update2(x<<1,l,mid,L,R);
	if(mid<R)update2(x<<1|1,mid+1,r,L,R);
}
int ans[100010],ans2[100010];
il vd dfs(int x,int l,int r){
	if(l==r){ans[l]=W[x];ans2[l]=lz2[x];return;}
	down(x);
	dfs(x<<1,l,mid),dfs(x<<1|1,mid+1,r);
}
#undef mid
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi(),q=gi();
	for(int i=1;i<=n;++i)w[i]=gi();
	char op[2];
	while(q--){
		scanf("%s",op);int x=gi();
		if(op[0]=='<'){
			if(x>0){
				if(x!=1)update2(1,1,100000,1,abs(x)-1);
				update(1,1,100000,abs(x),100000,1);
			}else if(abs(x)!=100000)update(1,1,100000,abs(x)+1,100000,1);
		}else{
			if(x<0){
				if(x!=-1)update2(1,1,100000,1,abs(x)-1);
				update(1,1,100000,abs(x),100000,-1);
			}else if(abs(x)!=100000)update(1,1,100000,abs(x)+1,100000,-1);
		}
		/*
	dfs(1,1,100000);
	for(int i=1;i<=n;++i){
		int o=abs(w[i]);
		if(ans[o])printf("%d ",o*ans[o]);
		else printf("%d ",w[i]*(ans2[o]?-1:1));
	}puts("");
		*/
	}
	dfs(1,1,100000);
	for(int i=1;i<=n;++i){
		int o=abs(w[i]);
		if(ans[o])printf("%d ",o*ans[o]);
		else printf("%d ",w[i]*(ans2[o]?-1:1));
	}puts("");
	return 0;
}