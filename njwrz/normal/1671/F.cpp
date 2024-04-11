#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int p[25][13][13][25],mod=998244353;
// 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int inv[30];
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	int re=1;
	FOR(i,x-y+1,x)re=re*i%mod;
	FOR(i,1,y)re=re*inv[i]%mod;
	RE re;
}
int f[25][13][13],g[25][13][13],val[25][13][13][13];
void solve(){
	int n,k,x;
	cin>>n>>k>>x;
	int ans=0;
	FOR(i,1,22)FOR(j,1,11)if(val[i][k][x][j]){
//		cout<<val[i][k][x][j]<<' ';
		add(ans,val[i][k][x][j]*C(n-i+j,j)%mod);
	}
	cout<<ans<<'\n';
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	inv[1]=1;
	FOR(i,2,22)inv[i]=mod-inv[mod%i]*(mod/i)%mod;
	p[0][0][0][1]=1;
	rep(i,0,22)FOR(j,0,11)FOR(k,0,11)FOR(lst,1,i+1)if(p[i][j][k][lst]){
		FOR(nxt,1,i+1){
			if(nxt-1+j<=11)add(p[i+1][nxt-1+j][k+(nxt>lst)][nxt],p[i][j][k][lst]);
		}
	}
	FOR(i,1,22)FOR(j,0,11)FOR(k,0,11)FOR(lst,1,i)add(f[i][j][k],p[i][j][k][lst]);
	FOR(i,1,22)FOR(j,0,11)FOR(k,0,11){
		g[i][j][k]=f[i][j][k];
		rep(ti,1,i)FOR(tj,0,j)FOR(tk,0,k)add(g[i][j][k],mod-f[ti][tj][tk]*g[i-ti][j-tj][k-tk]%mod);
	}
	val[0][0][0][0]=1;
	rep(i,0,22)FOR(j,0,11)FOR(k,0,11)FOR(cnt,0,11)if(val[i][j][k][cnt]){
		FOR(addi,1,22-i)FOR(addj,1,11-j)FOR(addk,0,11-k){
			add(val[i+addi][j+addj][k+addk][cnt+1],val[i][j][k][cnt]*g[addi][addj][addk]%mod);
		}
	}
//	cout<<g[3][3][2]<<'\n';RE 0;
	cin>>T;
	while(T--)solve();
	RE 0;
}