#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=20000,maxc=4000;
int n,p,m,f[maxc+10],ans[maxn+10];
struct node{int l,r; vector<pair<int,int> > v;}a[maxn*4+10];
vector<pair<int,int> > q[maxn+10];
void build(int p,int l,int r){
	a[p].l=l; a[p].r=r;
	if(l!=r){
		int mid=(l+r)/2; build(p*2,l,mid); build(p*2+1,mid+1,r);
	}
}
void ins(int p,int l,int r,pair<int,int> v){
	if(a[p].l==l&&a[p].r==r) a[p].v.push_back(v);
	else{
		int mid=(a[p].l+a[p].r)/2;
		if(r<=mid) ins(p*2,l,r,v); else if(l>mid) ins(p*2+1,l,r,v);
		else ins(p*2,l,mid,v),ins(p*2+1,mid+1,r,v);
	}
}
void dfs(int p){
	int cg[maxc+10]; memcpy(cg,f,sizeof f);
	for(int i=0;i<a[p].v.size();++i){
		pair<int,int> e=a[p].v[i];
		for(int j=maxc;j>=e.first;--j) f[j]=max(f[j],f[j-e.first]+e.second);
	}
	if(a[p].l==a[p].r){
		for(int i=0;i<q[a[p].l].size();++i){
			pair<int,int> e=q[a[p].l][i];
			ans[e.second]=f[e.first];
		}
	}else dfs(p*2),dfs(p*2+1);
	memcpy(f,cg,sizeof f);
}
int main(){
	scanf("%d%d",&n,&p);
	build(1,1,maxn);
	for(int i=1;i<=n;++i){
		int c,h,t; scanf("%d%d%d",&c,&h,&t);
		ins(1,t,t+p-1,make_pair(c,h));
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y); q[x].push_back(make_pair(y,i));
	}
	dfs(1); for(int i=1;i<=m;++i) printf("%d\n",ans[i]); return 0;
}