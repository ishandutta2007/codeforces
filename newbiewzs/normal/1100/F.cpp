#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=5e5+55;
int n,a[N],q;
struct node{
	int l,r,id;
}w[N],x[N];
int ans[N],pd[N];
#define mid ((l+r)>>1)
struct xo{
	int a[32];
	void init(int u){
		for(int i=30;i>=0;i--){
			if(u&(1<<i)){
				if(a[i])u^=a[i];
				else {
					a[i]=u;
					return ;
				}
			}
			if(!u)break;
		}
	}
	void clear(){
		for(int i=30;i>=0;i--)a[i]=0;
	}
}g[N],h[N],zuo;
void slove(int l,int r,int L,int R){
	if(L>R)return ;
	if(l==r){
		for(int k=L;k<=R;k++){
			ans[w[k].id]=a[l];
		}
		return ;
	}
	int top=0,jl;
	for(int i=L;i<=R;i++){
		if(w[i].r<=mid){
			x[++top]=w[i];
		}
	}
	jl=top;
	for(int i=L;i<=R;i++){
		if(w[i].l>mid){
			x[++top]=w[i];
		}
	}
	g[mid].init(a[mid]);
	for(int i=mid-1;i>=l;i--){
		g[i]=g[i+1];
		g[i].init(a[i]);
	}
	h[mid+1].init(a[mid+1]);
	for(int i=mid+2;i<=r;i++){
		h[i]=h[i-1];
		h[i].init(a[i]);
	}
	for(int i=L;i<=R;i++){
		if(w[i].l<=mid and w[i].r>mid and !pd[w[i].id]){
			zuo=g[w[i].l];pd[w[i].id]=1;
			for(int k=30;k>=0;k--){
				zuo.init(h[w[i].r].a[k]);
			}
			int da=0;
			for(int k=30;k>=0;k--){
				if((da^zuo.a[k])>da)da^=zuo.a[k];
			}
			ans[w[i].id]=da;
		}
	}
	for(int i=mid;i>=l;i--)g[i].clear();
	for(int i=mid+1;i<=r;i++)h[i].clear();
	for(int i=1;i<=top;i++){
		w[i+L-1]=x[i];
	}
	if(jl)slove(l,mid,L,L+jl-1);
	if(top-jl>0)slove(mid+1,r,L+jl,L+top-1);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	q=read();
	for(int i=1;i<=q;i++){
		w[i].l=read();w[i].r=read();w[i].id=i;
	}
	slove(1,n,1,q);
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}