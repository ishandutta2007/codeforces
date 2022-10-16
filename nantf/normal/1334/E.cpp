#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=500050,maxk=15,maxl=50,mod=998244353;
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
ll D,p[maxk];
int q,c[maxk],d[maxn],cnt[maxn][maxk],tmpc[maxk],pl,tot,C[maxl+10][maxl+10];
map<ll,int> id;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
void dfs(int dep,ll pr,int di){
	if(dep>pl){
		id[pr]=++tot;
		d[tot]=di;
		FOR(i,1,pl) cnt[tot][i]=tmpc[i];
		return;
	}
	FOR(i,0,c[dep]){
		tmpc[dep]=i;
		dfs(dep+1,pr,di*(i+1));
		if(i!=c[dep]) pr*=p[dep];
	}
}
void fac(ll D){
	ll tmp=D;
	for(ll i=2;i*i<=tmp;i++) if(tmp%i==0){
		p[++pl]=i;
		while(tmp%i==0) tmp/=i,c[pl]++;
	}
	if(tmp>1) p[++pl]=tmp,c[pl]=1;
	dfs(1,1,1);
}
int main(){
	FOR(i,0,maxl) C[i][0]=C[i][i]=1;
	FOR(i,1,maxl) FOR(j,1,i-1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	D=read();
	fac(D);
	q=read();
	while(q--){
		ll u=read(),v=read();
		if(u>v) swap(u,v);
		int x=id[u],y=id[v];
		if(v%u==0){
			int ans=1,sum=0;
			FOR(i,1,pl) sum+=cnt[y][i]-cnt[x][i]; 
			FOR(i,1,pl){
				ans=1ll*ans*C[sum][cnt[y][i]-cnt[x][i]]%mod;
				sum-=cnt[y][i]-cnt[x][i];
			}
			printf("%d\n",ans);
		}
		else{
			ll g=gcd(u,v),l=lcm(u,v),mn=1e18;
			int a=id[g],b=id[l],ans=0;
			if(d[x]-d[a]+d[y]-d[a]<mn) mn=d[x]-d[a]+d[y]-d[a],ans=0;
			if(d[x]-d[a]+d[y]-d[a]==mn){
				int pr=1,sum=0;
				FOR(i,1,pl) sum+=cnt[x][i]-cnt[a][i]; 
				FOR(i,1,pl){
					pr=1ll*pr*C[sum][cnt[x][i]-cnt[a][i]]%mod;
					sum-=cnt[x][i]-cnt[a][i];
				}
				FOR(i,1,pl) sum+=cnt[y][i]-cnt[a][i]; 
				FOR(i,1,pl){
					pr=1ll*pr*C[sum][cnt[y][i]-cnt[a][i]]%mod;
					sum-=cnt[y][i]-cnt[a][i];
				}
				ans=(ans+pr)%mod;
			}
			if(d[b]-d[x]+d[b]-d[y]<mn) mn=d[b]-d[x]+d[b]-d[y],ans=0;
			if(d[b]-d[x]+d[b]-d[y]==mn){
				int pr=1,sum=0;
				FOR(i,1,pl) sum+=cnt[b][i]-cnt[x][i]; 
				FOR(i,1,pl){
					pr=1ll*pr*C[sum][cnt[b][i]-cnt[x][i]]%mod;
					sum-=cnt[b][i]-cnt[x][i];
				}
				FOR(i,1,pl) sum+=cnt[b][i]-cnt[y][i]; 
				FOR(i,1,pl){
					pr=1ll*pr*C[sum][cnt[b][i]-cnt[y][i]]%mod;
					sum-=cnt[b][i]-cnt[y][i];
				}
				ans=(ans+pr)%mod;
			}
			printf("%d\n",ans);
		}
	}
}