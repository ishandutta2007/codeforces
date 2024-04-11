#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
ll ans=1ll<<60;
vector<int> del,v[500005];
int tag[1100005];
ll k[500005],b[500005],siz[500005],d[500005];

ll val(int x,int p){return p*k[x]+b[x];}

void change(int id,int l,int r,int c){
	if(!tag[id]){
		tag[id]=c,del.push_back(id);
		return;
	}
	if(l==r){
		if(val(c,l)<val(tag[id],l)) tag[id]=c;
		return;
	}
	int mid=(l+r)/2;
	if(k[c]>k[tag[id]]){
		if(val(c,mid)<val(tag[id],mid)) change(id<<1|1,mid+1,r,tag[id]),tag[id]=c;
		else change(id<<1,l,mid,c);
	}
	else{
		if(val(c,mid)<val(tag[id],mid)) change(id<<1,l,mid,tag[id]),tag[id]=c;
		else change(id<<1|1,mid+1,r,c);
	}
}

ll query(int id,int l,int r,int x){
	if(l==r) return val(tag[id],x);
	int mid=(l+r)/2;
	if(x<=mid) return min(val(tag[id],x),query(id<<1,l,mid,x));
	else return min(val(tag[id],x),query(id<<1|1,mid+1,r,x));
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(auto x:v[u]){
		if(x==fa) continue;
		dfs1(x,u);
		siz[u]+=siz[x];
	}
}

void dfs2(int u,int fa){
	d[u]=siz[u]*siz[u];
	for(auto x:v[u]){
		if(x==fa) continue;
		dfs2(x,u);
		d[u]=min(d[u],d[x]+(siz[u]-siz[x])*(siz[u]-siz[x]));
	}
	m=0;
	for(auto x:v[u]){
		if(x==fa) continue;
		ll tmp=query(1,1,n,siz[x]);
		ans=min(ans,d[x]+siz[x]*siz[x]-2*siz[x]*n+tmp+1ll*n*n);
		k[++m]=2*siz[x],b[m]=d[x]+siz[x]*siz[x]-2*siz[x]*n,change(1,1,n,m);
	}
	for(auto x:del) tag[x]=0;
	del.clear();
}

int main(){
	n=readint();
	int x,y;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint();
		v[x].push_back(y); v[y].push_back(x);
	}
	dfs1(1,-1);
	dfs2(1,-1);
	printf("%lld\n",1ll*n*(n-1)-(ans-n)/2);
	return 0;
}