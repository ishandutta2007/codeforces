#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
const int mod=998244353;
int n;
int f[255],inv[255],finv[255];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
void pref(){
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
struct DSU{
	int fa[255],siz[255];
	void init(int n){
		FOR(i,1,n)fa[i]=i;
	}
	int get(int x){
		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
	}
	void merge(int x,int y){
		x=get(x);y=get(y);
		fa[x]=y;if(x==y)siz[y]=1;
	}
}T;
int a[255],b[255],ans[255],cntemp[255];
int dp[255][255],val[255][255],val2[255][255],num[255][255],num2[255][255];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	pref();T.init(n);
	dp[0][0]=1;
	FOR(i,1,n)FOR(j,1,i)rep(k,0,i){
		add(dp[i][j],dp[k][j-1]*C(i-1,i-k-1)%mod*f[i-k-1]%mod);
	}
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	int tp=0;
	FOR(i,1,n)if(!a[i]&&!b[i])tp++;
	FOR(i,1,n)if(a[i]&&b[i])T.merge(a[i],b[i]);
	int cnt1=0,cnt2=0;
	FOR(i,1,n){
		if(!a[i]&&b[i])cnt1++,cntemp[T.get(b[i])]++;else if(a[i]&&!b[i])cnt2++,cntemp[T.get(a[i])]++;
	}
	int cnttwo=0;
	FOR(i,1,n)cnttwo+=cntemp[i]==2;
	cnt1-=cnttwo;cnt2-=cnttwo;
	int t=min(cnt1,cnt2);
	FOR(i,0,t+cnttwo){
		FOR(j,0,min(cnttwo,i)){
			FOR(k,0,j){
				int res=i-j;
				add(val2[i][k],dp[j][k]*C(cnttwo,j)%mod*C(cnt1+cnttwo-j,res)%mod*C(cnt2+cnttwo-j,res)%mod*f[res]%mod);
			}
		}
		FOR(j,0,min(cnttwo,i))FOR(k,j,min(cnttwo,i)){
			if((k-j)&1)add(num2[i][j],mod-val2[i][k]*C(k,j)%mod);
			else add(num2[i][j],val2[i][k]*C(k,j)%mod);
		}
	}
	int cntroll=0,cntl=0;
	FOR(i,1,n)if(T.get(i)==i){
		if(T.siz[i])cntroll++;else cntl++;
	}
	int cnt0=cntl-cnt1-cnt2-cnttwo;
	FOR(i,0,t+cnttwo){
		FOR(j,0,min(cnttwo,i)){
			int hav=cntl-i;
			FOR(k,0,hav)add(val[i][j+k],dp[hav][k]*num2[i][j]%mod);
		}
	}
	FOR(i,0,cntl){
		FOR(j,0,i)FOR(k,0,cntl)if((i-j)&1){
			add(num[j][k],mod-val[i][k]*C(i,j)%mod);
		}else add(num[j][k],val[i][k]*C(i,j)%mod);
	}
	FOR(i,0,cntl)ans[cntroll+i]=num[0][i];
	rep(i,0,n)cout<<ans[n-i]*f[tp]%mod<<' ';
	RE 0;
}