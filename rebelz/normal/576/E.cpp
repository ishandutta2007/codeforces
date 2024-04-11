#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct dsu{
	int f[500005],d[500005],siz[500005];
	stack<int> gar;
	bool merge(int x,int y){
		int fx=x,fy=y,dx=0,dy=0;
		while(f[fx]!=fx) dx^=d[fx],fx=f[fx];
		while(f[fy]!=fy) dy^=d[fy],fy=f[fy];
		if(fx==fy) return false;
		if(siz[fx]<siz[fy]) f[fx]=fy,siz[fy]+=siz[fx],d[fx]=dx^dy^1,gar.push(fx);
		else f[fy]=fx,siz[fx]+=siz[fy],d[fy]=dx^dy^1,gar.push(fy);
		return true;
	}
	bool check(int x,int y){
		int fx=x,fy=y,dx=0,dy=0;
		while(f[fx]!=fx) dx^=d[fx],fx=f[fx];
		while(f[fy]!=fy) dy^=d[fy],fy=f[fy];
		if(fx!=fy||dx!=dy) return true;
		return false;
	}
	void undo(){
		assert(!gar.empty());
		int tmp=gar.top(),x=tmp; gar.pop();
		d[x]=0;
		do{
			tmp=f[tmp];
			siz[tmp]-=siz[x];
		}while(f[tmp]!=tmp);
		f[x]=x;
	}
}ds[55];

int n,m,k,q;
int a[500005],b[500005],c[500005],d[500005],now[500005],nxt[500005],col[500005];
vector<pii> v[1100000];

void change(int id,int l,int r,int ql,int qr,pii x){
	if(ql>qr) return;
	if(l==ql&&r==qr) return (void)(v[id].push_back(x));
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,x);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,x);
	else change(id<<1,l,mid,ql,mid,x),change(id<<1|1,mid+1,r,mid+1,qr,x);
}

void solve(int id,int l,int r){
	for(int i=0;i<v[id].size();i++) if(!ds[v[id][i].fi].merge(a[v[id][i].se],b[v[id][i].se])) v[id][i].fi=0;
	if(l==r){
		if(ds[d[l]].check(a[c[l]],b[c[l]])){
			col[c[l]]=d[l];
			printf("YES\n");
			change(1,1,q,l+1,nxt[l]-1,mp(d[l],c[l]));
		}
		else{
			printf("NO\n");
			change(1,1,q,l+1,nxt[l]-1,mp(col[c[l]],c[l]));
		}
		for(auto x:v[id]) if(x.fi) ds[x.fi].undo();
		v[id].clear();
		return;
	}
	int mid=(l+r)/2;
	solve(id<<1,l,mid);
	solve(id<<1|1,mid+1,r);
	for(auto x:v[id]) if(x.fi) ds[x.fi].undo();
	v[id].clear();
}

int main(){
	n=readint(); m=readint(); k=readint(); q=readint();
	for(int i=1;i<=m;i++) a[i]=readint(),b[i]=readint();
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) ds[i].f[j]=j,ds[i].siz[j]=1;
	for(int i=1;i<=q;i++) c[i]=readint(),d[i]=readint();
	for(int i=1;i<=m;i++) now[i]=q+1;
	for(int i=q;i>=1;i--){
		nxt[i]=now[c[i]];
		now[c[i]]=i;
	}
	solve(1,1,q);
	return 0;
}