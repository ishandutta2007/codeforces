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

const int cys=998244353;
int n,m;
int du[1005],q[1005],a[1005];
ll fac[1000005],inv[1000005],d[1005];
vector<int> adj[1005],adj1[1005];
bool vis[1005];

ll mod(ll x){return x>=cys?x-cys:x;}
ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) adj[i].clear(),adj1[i].clear(),du[i]=0;
		for(int i=1;i<=n;i++) a[i]=readint();
		int x,y;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint();
			adj1[x].pb(y);
			adj[y].pb(x),du[x]++;
		}
		int front=0,rear=0;
		for(int i=1;i<=n;i++) d[i]=0;
		for(int i=1;i<=n;i++) if(!du[i]) q[rear++]=i,d[i]=1;
		while(front<rear){
			int t=q[front++];
			for(auto v:adj[t]){
				d[v]=mod(d[v]+d[t]);
				if(!(--du[v])) q[rear++]=v;
			}
		}
		int res=0;
		for(int i=1;i<=n;i++) if(a[i]) res=-1;
		if(!res){
			printf("0\n");
			continue;
		}
		res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) vis[j]=a[j];
			for(int j=1;j<=n;j++){
				if(vis[j]){
					a[j]--;
					for(auto v:adj1[j]) a[v]++;
				}
			}
			bool fl=0;
			for(int j=1;j<=n;j++) if(a[j]) fl=1;
			if(!fl){
				res=i;
				break;
			}
		}
		if(res){
			printf("%d\n",res);
			continue;
		}
		ll ans=n;
		for(int i=1;i<=n;i++) ans=(ans+a[i]*d[i])%cys;
		printf("%lld\n",ans);
	}
	return 0;
}