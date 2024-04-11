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

int n,tot;
int v[400005],nxt[400005],h[200005];
ll a[200005],b[200005],d[200005][2];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	vector<ll> t[2]; t[0].clear(); t[1].clear();
	vector<pll> g;
	d[u][0]=d[u][1]=1ll<<60;
	if(u!=1&&!nxt[h[u]]){
		d[u][0]=d[u][1]=a[u];
		return;
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		ll tmp0=1ll<<60,tmp1=1ll<<60;
		if(b[v[p]]>=b[u]) chkmin(tmp1,d[v[p]][1]);
		else chkmin(tmp0,d[v[p]][1]+a[v[p]]);
		if(b[v[p]]<=b[u]) chkmin(tmp0,d[v[p]][0]);
		else chkmin(tmp1,d[v[p]][0]+a[v[p]]);
		if(b[v[p]]==b[u]) g.pb(mp(tmp0,tmp1));
		else if(b[v[p]]>b[u]) t[1].pb(tmp1);
		else if(b[v[p]]<b[u]) t[0].pb(tmp0);
//		cout<<"val "<<u<<' '<<v[p]<<' '<<tmp0<<' '<<tmp1<<endl;
	}
	sort(g.begin(),g.end(),[&](pll x,pll y){return x.fi-x.se<y.fi-y.se;});
	ll sum=0;
	for(auto r:g) sum+=r.se;
	for(auto r:t[0]) sum+=r;
	for(auto r:t[1]) sum+=r;
	chkmin(d[u][0],sum+(ll)max((int)t[0].size(),(int)t[1].size()+(int)g.size())*a[u]+(u!=1)*a[u]);
	chkmin(d[u][1],sum+(ll)max((int)t[0].size(),(int)t[1].size()+(int)g.size())*a[u]+(u!=1)*a[u]);
	if(t[0].size()) chkmin(d[u][0],sum+(ll)max((int)t[0].size()-1,(int)t[1].size()+(int)g.size())*a[u]+a[u]);
	if(t[1].size()+g.size()>=1) chkmin(d[u][1],sum+(ll)max((int)t[0].size(),(int)t[1].size()-1+(int)g.size())*a[u]+a[u]);
	for(int i=1;i<=g.size();i++){
		sum+=g[i-1].fi-g[i-1].se;
		chkmin(d[u][0],sum+(ll)max((int)t[0].size()+i,(int)t[1].size()+(int)g.size()-i)*a[u]+(u!=1)*a[u]);
		chkmin(d[u][1],sum+(ll)max((int)t[0].size()+i,(int)t[1].size()+(int)g.size()-i)*a[u]+(u!=1)*a[u]);
		if(t[0].size()+i>=1) chkmin(d[u][0],sum+(ll)max((int)t[0].size()-1+i,(int)t[1].size()+(int)g.size()-i)*a[u]+a[u]);
		if(t[1].size()+g.size()-i>=1) chkmin(d[u][1],sum+(ll)max((int)t[0].size()+i,(int)t[1].size()-1+(int)g.size()-i)*a[u]+a[u]);
	}
//	cout<<"dfs "<<u<<' '<<d[u][0]<<' '<<d[u][1]<<endl;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) b[i]=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs(1,-1);
	printf("%lld\n",min(d[1][0],d[1][1]));
	return 0;
}