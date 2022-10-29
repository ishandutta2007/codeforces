#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pb push_back
#define vi vector<int>
using namespace std;
const int N=4e5+9;
int ls[N*40],rs[N*40],sum[N*40];
struct node{
	int len,ch[26],fa;
}dian[N];
int tot,n,maxn[N],rt[N],cnt,last;
void build(int &rt,int l,int r,int p){
	if(!rt)rt=++cnt;
	sum[rt]++;
	if(l==r)return;
	int m=l+r>>1;
	if(p<=m)build(ls[rt],l,m,p);
	else build(rs[rt],m+1,r,p);
}
int merge(int &o,int &s){
	if(!o||!s)return o|s;
	int t=++cnt;
	sum[t]=sum[o]+sum[s];
	ls[t]=merge(ls[o],ls[s]);
	rs[t]=merge(rs[o],rs[s]);
	return t;
}
int query(int rt,int l,int r,int L,int R){
	if(!rt)return 0;
	if(L<=l&&r<=R)return sum[rt]; 
	int res=0;
	int m=l+r>>1;
	if(L<=m)res+=query(ls[rt],l,m,L,R);
	if(R>m)res+=query(rs[rt],m+1,r,L,R);
	return res;
}
void add(int c,int i){
	int p=last,np=last=++tot;
	build(rt[np],1,n,i);
	maxn[np]=i;
	dian[np].len=dian[p].len+1;
	for(;p&&!dian[p].ch[c];p=dian[p].fa)dian[p].ch[c]=np;
	if(!p)dian[np].fa=1;
	else{
		int q=dian[p].ch[c];
		if(dian[q].len==dian[p].len+1)dian[np].fa=q;
		else{
			int nq=++tot;
			dian[nq]=dian[q];
			dian[nq].len=dian[p].len+1;
			dian[q].fa=dian[np].fa=nq;
			for(;p&&dian[p].ch[c]==q;p=dian[p].fa)dian[p].ch[c]=nq;
		}
	}
}
char s[N];
vi g[N];
int f[N],h[N];
void dfs(int u){
	for(auto v:g[u]){
		dfs(v);
		maxn[u]=max(maxn[v],maxn[u]);
		rt[u]=merge(rt[u],rt[v]);
	}
}
void dfs2(int u){
	for(auto v:g[u]){
		if(u==1)f[v]=1,h[v]=v;
		else{
			int val=query(rt[h[u]],1,n,maxn[v]-dian[v].len+dian[h[u]].len,maxn[v]-1);
			if(val){
				f[v]=f[u]+1;
				h[v]=v;
			}
			else{
				f[v]=f[u];
				h[v]=h[u];
			}
		}
		dfs2(v);
	}
}
int main(){
	last=tot=1;
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n+1)add(s[i]-'a',i);
	rep(i,2,tot+1)g[dian[i].fa].pb(i);
	dfs(1);
	dfs2(1);
	int ans=0;
	rep(i,2,tot+1)ans=max(ans,f[i]);
	printf("%d\n",ans);
}