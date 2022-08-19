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

const int cys=1000000007;
int n;
ll a[5000005],t[5000005],res[5000005];
pll tmp[5000005];

namespace gen{
	int m;
	ll seed=0,base=0;
	ll p[200005],k[200005],b[200005],w[200005];
	ll rnd(){
		ll ret=seed;
		seed=(seed*base+233)%1000000007;
		return ret;
	}
	void work(){
		m=readint();
		for(int i=1;i<=m;i++) p[i]=readint(),k[i]=readint(),b[i]=readint(),w[i]=readint();
		for(int i=1;i<=m;i++){
			seed=b[i],base=w[i];
			for(int j=p[i-1]+1;j<=p[i];j++) t[j]=rnd()%2,a[j]=rnd()%k[i]+1;
		}
	}
}

int main(){
	n=readint();
	gen::work();
	ll sum[2]={0,0};
	for(int i=1;i<=n;i++) sum[t[i]]+=a[i];
	if(sum[0]==sum[1]){
		ll ans=1;
		for(int i=1;i<=n;i++) ans=((a[i]^(1ll*i*i))+1)%cys*ans%cys;
		printf("%lld\n",ans);
		return 0;
	}
	if(sum[0]>sum[1]){
		for(int i=1;i<=n;i++) t[i]^=1;
	}
	int pl=1;
	if(t[1]==1){
		a[1]--,res[1]++;
		pl=0;
		for(int i=1;i<=n;i++){
			if(t[i]==0){
				pl=i;
				break;
			}
		}
		if(!pl){
			ll ans=1;
			for(int i=1;i<=n;i++) ans=((res[i]^(1ll*i*i))+1)%cys*ans%cys;
			printf("%lld\n",ans);
			return 0;
		}
		for(int i=pl;i<=n;i++) tmp[i-pl+1]=mp(a[i],t[i]);
		for(int i=1;i<pl;i++) tmp[i+n-pl+1]=mp(a[i],t[i]);
		for(int i=1;i<=n;i++) a[i]=tmp[i].fi,t[i]=tmp[i].se;
		res[1]=0;
		res[1+n-pl+1]=1;
	}
	for(int i=1;i<=n;i++) if(!t[i]) res[i]+=a[i];
	ll now=0;
	for(int i=1;i<=n;i++){
		if(t[i]==0) now+=a[i];
		else if(t[i]==1){
			if(now>=a[i]) now-=a[i],res[i]+=a[i],a[i]=0;
			else res[i]+=now,a[i]-=now,now=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]==1){
			if(now>=a[i]) now-=a[i],res[i]+=a[i],a[i]=0;
			else res[i]+=now,a[i]-=now,now=0;
		}
	}
	ll ans=1;
	for(int i=pl;i<=n;i++) ans=((res[i-pl+1]^(1ll*i*i))+1)%cys*ans%cys;
	for(int i=1;i<pl;i++) ans=((res[i+n-pl+1]^(1ll*i*i))+1)%cys*ans%cys;
	printf("%lld\n",ans);
	return 0;
}