// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,m,timer;
int a[200005],p[200005],suf[200005],mark[200005];
ll val1[200005];
pll d[200005],val[200005];
vector<int> vec[200005];

ll mod(ll x){return x>=cys?x-cys:x;}

void add(int x,pll c){
	for(;x<=m;x+=(x&(-x))) val[x].fi=mod(val[x].fi+c.fi),val[x].se=mod(val[x].se+c.se);
}

pll ask(int x){
	pll ret=mp(0,0);
	for(;x;x-=(x&(-x))){
		ret.fi=mod(ret.fi+val[x].fi);
		ret.se=mod(ret.se+val[x].se);
	}
	return ret;
}

void add1(int x,ll c){
	for(;x<=n;x+=(x&(-x))){
		if(mark[x]!=timer) mark[x]=timer,val1[x]=0;
		val1[x]=mod(val1[x]+c);
	}
}

ll ask1(int x){
	ll ret=0;
	for(;x;x-=(x&(-x))){
		if(mark[x]!=timer) mark[x]=timer,val1[x]=0;
		ret=mod(ret+val1[x]);
	}
	return ret;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) p[i]=a[i]=readint();
		sort(p+1,p+n+1);
		m=unique(p+1,p+n+1)-p-1;
		for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+m+1,a[i])-p;
		suf[n+1]=0;
		for(int i=n;i>=1;i--) suf[i]=max(suf[i+1],a[i]);
		for(int i=1;i<=m;i++) val[i]=mp(0,0);
		ll ans=0;
		for(int i=1;i<=n;i++){
			pll tmp=ask(a[i]-1);
			d[i]=mp(mod(tmp.fi+1),mod(tmp.se+tmp.fi+1));
			add(a[i],d[i]);
			ans=mod(ans+d[i].se);
		}
//		cout<<ans<<endl;
		for(int i=1;i<=m;i++) vec[i].clear();
		for(int i=1;i<=n;i++) vec[a[i]].pb(i);
		int now=0;
		for(int i=1;i<=n;i++) val1[i]=0;
		timer++;
		for(int i=m;i>=1;i--){
			for(auto r:vec[i]){
				if(r<now){
					ll tmp=mod(cys+ask1(n)-ask1(r));
					ans=mod(ans+cys-tmp*d[r].fi%cys);
					add1(r,tmp);
				}
				else{
					timer++;
					ans=mod(ans+cys-d[r].fi);
					add1(r,1);
					now=r;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}