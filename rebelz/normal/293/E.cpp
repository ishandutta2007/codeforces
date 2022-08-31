#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,dl,dw,tot,cnt,sum,rt;
ll ans;
int v[200005],c[200005],nxt[200005],h[100005],ms[100005],siz[100005],a[100005];
pii dep[100005];
bool vis[100005];

int lowbit(int x){return x&(-x);}
void add(int x){for(;x<=n+1;x+=lowbit(x))a[x]++;}
void del(int x){for(;x<=n+1;x+=lowbit(x))a[x]--;}
ll ask(int x){ll ret=0;for(;x;x-=lowbit(x))ret+=a[x];return ret;}

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void getroot(int u,int fa){
	ms[u]=0,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||vis[v[p]]) continue;
		getroot(v[p],u);
		siz[u]+=siz[v[p]];
		ms[u]=max(ms[u],siz[v[p]]);
	}
	ms[u]=max(ms[u],sum-siz[u]);
	if(ms[u]<ms[rt]) rt=u;;
}

void getdep(int u,int fa,int d1,int d2){
	dep[++cnt]=mp(d1,d2);
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&!vis[v[p]]) getdep(v[p],u,d1+c[p],d2+1);
}

ll work(int u,int d1,int d2){
	cnt=0;
	getdep(u,-1,d1,d2);
	sort(dep+1,dep+cnt+1);
	int l=1,r=cnt; ll ret=0;
	while(r){
		while(l<=cnt&&dep[l].fi+dep[r].fi<=dw) add(dep[l].se+1),l++;
		if(dl>=dep[r].se) ret+=ask(dl-dep[r].se+1);
		r--;
	}
	for(int i=1;i<=cnt;i++) if(2*dep[i].fi<=dw&&2*dep[i].se<=dl) ret--;
	for(int i=1;i<l;i++) del(dep[i].se+1);
	return ret/2;
}

void solve(int u){
	ans+=work(u,0,0);
	vis[u]=true;
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		ans-=work(v[p],c[p],1);
		sum=siz[v[p]],rt=0,ms[rt]=1<<30;
		getroot(v[p],u);
		solve(rt);
	}
}

int main(){
	n=readint(); dl=readint(); dw=readint();
	int x,y;
	for(int i=2;i<=n;i++){
		x=readint(); y=readint();
		addedge(x,i,y);
	}
	sum=n,rt=0,ms[rt]=1<<30;
	getroot(1,-1);
	solve(rt);
	cout<<ans<<endl;
	return 0;
}