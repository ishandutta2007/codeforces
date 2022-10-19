/*/////////////////////////////////
codeforces 547E E. Mike and Friends
*//////////////////////////////////

#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10,M=N*40;int n,Q;char s[N];
namespace Tree {
	int rt[N];
	struct ST {
		int sz,ls[M],rs[M],sum[M];
		void update(int &x,int l,int r,int p) {if(!x) x=++sz;++sum[x];if(l==r) return;int mid=(l+r)>>1;if(p<=mid) update(ls[x],l,mid,p);else update(rs[x],mid+1,r,p);}
		int query(int x,int l,int r,int L,int R) {if(!x) return 0;if(L<=l && r<=R) return sum[x];int mid=(l+r)>>1,res=0;if(L<=mid) res+=query(ls[x],l,mid,L,R);if(R>mid) res+=query(rs[x],mid+1,r,L,R);return res;}
		int merge(int x,int y) {if(!x || !y) return x+y;int z=++sz;ls[z]=merge(ls[x],ls[y]);rs[z]=merge(rs[x],rs[y]);sum[z]=sum[x]+sum[y];return z;}} tr;
	}
using namespace Tree;
namespace SAM {
	int p[N],b[N],c[N],id[N];
	struct SAM {
		int sz,las,fa[N],mx[N],ch[N][26];
		void extend(int x) {int p,q,np,nq;if(ch[las][x]) {p=las;q=ch[p][x];if(mx[q]==mx[p]+1) {las=q;return;}nq=++sz;mx[nq]=mx[p]+1;memcpy(ch[nq],ch[q],sizeof(ch[q]));fa[nq]=fa[q];fa[q]=nq;for(; p && ch[p][x]==q; p=fa[p]) ch[p][x]=nq;las=nq;return;}
			p=las;np=las=++sz;mx[np]=mx[p]+1;for(; p && !ch[p][x]; p=fa[p]) ch[p][x]=np;if(!p) fa[np]=1;else {q=ch[p][x];if(mx[q]==mx[p]+1) fa[np]=q;else {nq=++sz;mx[nq]=mx[p]+1;memcpy(ch[nq],ch[q],sizeof(ch[q]));fa[nq]=fa[q];fa[np]=fa[q]=nq;for(; ch[p][x]==q; p=fa[p]) ch[p][x]=nq;}}}
		void merge() {for(int i=1; i<=sz; ++i) b[mx[i]]++;for(int i=1; i<=sz; ++i) b[i]+=b[i-1];for(int i=sz; i; --i) c[b[mx[i]]--]=i;for(int i=sz,x; i>1; --i) x=c[i],rt[fa[x]]=tr.merge(rt[x],rt[fa[x]]);}
	} S;
}
using namespace SAM;
int main() {
	scanf("%d%d" , &n , &Q);S.sz=S.las=1;
	for(int i=1,l; i<=n; ++i) {scanf("%s",s+1);l=strlen(s+1);S.las=1;for(int j=1; j<=l; ++j) S.extend(s[j]-'a'),tr.update(rt[S.las],1,n,i);p[i]=S.las;}
	S.merge();while(Q--) {int l,r,id;scanf("%d%d%d" , &l , &r , &id);printf("%d\n" , tr.query(rt[p[id]],1,n,l,r));}return 0;
}