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

int n,m,tot,cnt; ll now;
int v[4005],nxt[4005],h[2005],a[2005],b[2005],fr[2005];
bool vis[2005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void add(int u){
	while(!vis[u]) vis[u]=1,now+=b[u],cnt++,u=fr[u];
}

bool dfs(int u,int fa,ll val){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(val<=a[v[p]]) continue;
		if(!vis[u]&&vis[v[p]]){
			add(u);
			return true;
		}
		if(vis[v[p]]) continue;
		if(fr[v[p]]){
			add(v[p]),add(u);
			return true;
		}
		fr[v[p]]=u;
		if(dfs(v[p],u,val+b[v[p]])) return true;
	}
	return false;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=2;i<=n;i++) a[i]=readint();
		for(int i=2;i<=n;i++) b[i]=readint();
		for(int i=1;i<=n;i++) h[i]=0; tot=0;
		for(int i=1;i<=m;i++) addedge(readint(),readint());
		ll l=1,r=1000000000+1,res=0;
		while(l<=r){
			ll mid=(l+r)/2;
			for(int i=1;i<=n;i++) vis[i]=0;
			vis[1]=1;
			cnt=1,now=mid;
			bool can=1;
			while(cnt<n){
				for(int i=1;i<=n;i++) fr[i]=0;
				bool fl=0;
				for(int i=1;i<=n;i++){
					if(vis[i]){
						if(dfs(i,-1,now)){
							fl=1;
							break;
						}
					}
				}
				if(!fl&&cnt<n){
					can=0;
					break;
				}
			}
			if(can) res=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",res);
	}
	return 0;
}