#include<bits/stdc++.h>

using namespace std;

#define N 420000

int n,p,np,c[N][30],b[N],bb[N],rt[N],fa[N],mx[N],ls[N<<5],rs[N<<5],cnt,tot,rgt[N],pos[N],f[N],ans;
bool seg[N<<5];
char s[N];

void upd(int x){seg[x]=seg[ls[x]]|seg[rs[x]];}

void ins(int &x,int l,int r,int t){
	if (!x) x=++tot; ++seg[x];
	if (l==r) return;
	int mid=(l+r)>>1;
	if (t<=mid) ins(ls[x],l,mid,t);
	else ins(rs[x],mid+1,r,t);
}

int qry(int x,int l,int r,int L,int R){
	if (!x||L>R) return 0;
	if (l>=L&&r<=R) return seg[x];
	int mid=(l+r)>>1,ret=0;
	if (L<=mid) ret+=qry(ls[x],l,mid,L,R);
	if (R>mid) ret+=qry(rs[x],mid+1,r,L,R);
	return ret;
}

int merge(int x,int y){
	if (!x||!y) return x|y;
	int z=++tot;
	ls[z]=merge(ls[x],ls[y]);
	rs[z]=merge(rs[x],rs[y]);
	upd(z);
	return z;
}

void extend(int w){
	p=np; np=++cnt; rgt[np]=mx[np]=mx[p]+1;
	ins(rt[np],1,n,rgt[np]);
	for (;p&&!c[p][w];p=fa[p]) c[p][w]=np;
	if (!p) fa[np]=1;
	else{
		int q=c[p][w];
		if (mx[q]==mx[p]+1) fa[np]=q;
		else{
			int nq=++cnt; mx[nq]=mx[p]+1; rgt[nq]=rgt[np];
			memcpy(c[nq],c[q],sizeof c[nq]);
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for (;p&&c[p][w]==q;p=fa[p]) c[p][w]=nq;
		}
	}
}

int main(){
	scanf("%d%s",&n,s+1);
	np=++cnt; for (int i=1;i<=n;++i) extend(s[i]-'a');
	for (int i=1;i<=cnt;++i) ++bb[mx[i]];
	for (int i=1;i<=n;++i) bb[i]+=bb[i-1];
	for (int i=1;i<=cnt;++i) b[bb[mx[i]]--]=i;
	for (int i=cnt;i>1;--i) rt[fa[b[i]]]=merge(rt[fa[b[i]]],rt[b[i]]);
	pos[1]=1;
	for (int i=2;i<=cnt;++i){
		int u=b[i],v=pos[fa[b[i]]];
		if (v==1||qry(rt[v],1,n,rgt[u]-mx[u]+mx[v],rgt[u]-1)){
			f[u]=f[v]+1; pos[u]=u;
		}
		else pos[u]=pos[v];
		ans=max(ans,f[u]);
	}
	printf("%d\n",ans);
	
	return 0;
}