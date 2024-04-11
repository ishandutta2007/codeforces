#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=133333,maxnd=maxn*200,mod=998244353,INF=1e9;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,m,lft[maxn],rig[maxn],ans[maxn],rt[maxn],cnt,ls[maxnd],rs[maxnd],mn[maxnd];
struct seg{
	int l,r,id;
	bool operator<(const seg &s)const{
		return r-l>s.r-s.l;
	}
}s[maxn];
inline int newnode(){
	int now=++cnt;
	mn[now]=INF;
	return now;
}
void update(int &x,int l,int r,int p,int v){
	if(!x) x=newnode();
	mn[x]=min(mn[x],v);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(mid>=p) update(ls[x],l,mid,p,v);
	else update(rs[x],mid+1,r,p,v);
}
int query(int x,int l,int r,int ql,int qr){
	if(!x) return INF;
	if(l>=ql && r<=qr) return mn[x];
	int mid=(l+r)>>1,ans=INF;
	if(mid>=ql) ans=min(ans,query(ls[x],l,mid,ql,qr));
	if(mid<qr) ans=min(ans,query(rs[x],mid+1,r,ql,qr));
	return ans;
}
void update(int o,int l,int r,int x,int y,int v){
	update(rt[o],1,n,y,v);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(mid>=x) update(lson,x,y,v);
	else update(rson,x,y,v);
}
int query(int o,int l,int r,int xl,int yl,int xr,int yr){
	if(l>=xl && r<=xr) return query(rt[o],1,n,yl,yr);
	int mid=(l+r)>>1,ans=INF;
	if(mid>=xl) ans=min(ans,query(lson,xl,yl,xr,yr));
	if(mid<xr) ans=min(ans,query(rson,xl,yl,xr,yr));
	return ans;
}
int solve(int l,int r){
	if(l>r) return 0;
	int id=query(1,1,n,l,l,r,r);
	if(id==INF) return 0;
	return solve(l,lft[id]-1)+solve(rig[id]+1,r)+rig[id]-lft[id]+1;
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		s[i].l=lft[i]=read();
		s[i].r=rig[i]=read();
		s[i].id=i;
	}
	sort(s+1,s+m+1);
	int cur=1;
	ROF(i,n,1){
		while(cur<=m && s[cur].r-s[cur].l+1>=i){
			update(1,1,n,s[cur].l,s[cur].r,s[cur].id);
			cur++;
		}
		ans[i]=solve(1,n);
	}
	FOR(i,1,n) printf("%d\n",ans[i]);
}