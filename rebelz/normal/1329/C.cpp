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

int n,m;
int a[1100000];
pii b[1100000];
bool vis[1100000];

pii getmin(int u,int t){
	pii ret=mp(1<<30,0);
	if(u>=(1<<n)) return ret;
	if(a[u]>t) chkmin(ret,mp(a[u],u));
	chkmin(ret,min(getmin(u<<1,t),getmin(u<<1|1,t)));
	return ret;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<(1<<n);i++) a[i]=readint();
		for(int i=1;i<(1<<n);i++) b[i]=mp(0,0),vis[i]=0;
		ll ans=0;
		for(int i=(1<<m)-1;i>=1;i--){
			b[i]=getmin(i,max(b[i<<1].fi,b[i<<1|1].fi));
			vis[b[i].se]=1;
			ans+=b[i].fi;
		}
		printf("%lld\n",ans);
		for(int i=(1<<n)-1;i>=1;i--) if(!vis[i]) printf("%d ",i);
		printf("\n");
	}
	return 0;
}