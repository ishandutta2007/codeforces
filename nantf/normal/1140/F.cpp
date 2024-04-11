#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030;
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
struct point{
	int l,r,x,y;
}p[maxn];
int n,nd,fa[maxn*2],sz[maxn*2],xs[maxn*2],ys[maxn*2],stk[maxn][3],tp;
vector<PII> vec[maxn*4];
map<PII,int> mp;
ll s,ans[maxn];
int getfa(int x){return x==fa[x]?x:getfa(fa[x]);}
inline void unite(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x==y) return;
	if(sz[x]>sz[y]) swap(x,y);
	stk[++tp][0]=x;stk[tp][1]=y;stk[tp][2]=sz[y];
	sz[y]=max(sz[y],sz[x]+1);
	fa[x]=y;
	s-=1ll*xs[x]*ys[x]+1ll*xs[y]*ys[y];
	xs[y]+=xs[x];
	ys[y]+=ys[x];
	s+=1ll*xs[y]*ys[y];
}
inline void undo(){
	int x=stk[tp][0],y=stk[tp][1];
	sz[y]=stk[tp--][2];
	s-=1ll*xs[y]*ys[y];
	xs[y]-=xs[x];
	ys[y]-=ys[x];
	s+=1ll*xs[x]*ys[x]+1ll*xs[y]*ys[y];
	fa[x]=x;
}
void update(int o,int l,int r,int ql,int qr,int x,int y){
	if(l>=ql && r<=qr) return void(vec[o].push_back(MP(x,y)));
	int mid=(l+r)>>1;
	if(mid>=ql) update(lson,ql,qr,x,y);
	if(mid<qr) update(rson,ql,qr,x,y);
}
void solve(int o,int l,int r){
	int tmp=tp;
	FOR(i,0,(int)vec[o].size()-1) unite(vec[o][i].first,vec[o][i].second);
	if(l==r) ans[l]=s;
	else{
		int mid=(l+r)>>1;
		solve(lson);solve(rson);
	}
	while(tp>tmp) undo();
}
int main(){
	n=read();
	FOR(i,1,n){
		int x=read(),y=read();
		PII tmp=MP(x,y);
		if(mp[tmp]) p[mp[tmp]].r=i-1,mp[tmp]=0;
		else p[mp[tmp]=++nd]=(point){i,n,x,y};
	}
	FOR(i,1,nd) update(1,1,n,p[i].l,p[i].r,p[i].x,p[i].y+300000);
	FOR(i,1,300000) fa[i]=i,sz[i]=xs[i]=1;
	FOR(i,300001,600000) fa[i]=i,sz[i]=ys[i]=1;
	solve(1,1,n);
	FOR(i,1,n) printf("%I64d ",ans[i]);
}