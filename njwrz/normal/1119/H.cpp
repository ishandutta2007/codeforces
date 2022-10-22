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
const int mod=998244353,inv=(mod+1)/2;
int m,k;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
struct node{
	int val[1<<17];
	void operator *=(const node &x){
		rep(i,0,m)val[i]=val[i]*x.val[i]%mod;
	}
	void operator +=(const node &x){
		rep(i,0,m)add(val[i],x.val[i]);
	}
	void operator -=(const node &x){
		rep(i,0,m)add(val[i],mod-x.val[i]);
	}
	void fwt(int x){
		for(int k=2,o=1;k<=m;k<<=1,o<<=1){
			for(int i=0;i<m;i+=k)rep(p,0,o){
				add(val[i+p],val[i+p+o]);
				val[i+p+o]=(val[i+p]-val[i+p+o]-val[i+p+o]+mod+mod)%mod;
				val[i+p]=val[i+p]*x%mod;val[i+p+o]=val[i+p+o]*x%mod;
			}
		}
		//xor fwt(1) :fwt(1/2) -1/2 
	}
}fwt;
struct bit{
	int val[1<<17],dp[18][1<<17][2];
	void solve(){
		rep(i,0,m)dp[0][i][0]=val[i];
		rep(i,0,k){
			rep(mask,0,m)rep(t,0,2)if(dp[i][mask][t]){
				int msk=mask;
				if(mask&(1<<i))msk-=1<<i;
				rep(nxt,0,2){
					add(dp[i+1][msk+nxt*(1<<i)][t^(nxt&((mask>>i)&1))],dp[i][mask][t]);
				}
			}
		}
	}
}T[3];
int n;
int pw[4][100005];
int ans[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;m=1<<k;
	int x,y,z;
	cin>>x>>y>>z;
	pw[0][1]=(x+y+z)%mod;
	pw[1][1]=(x-y+z+mod)%mod;
	pw[2][1]=(x+y-z+mod)%mod;
	pw[3][1]=(x-y-z+mod+mod)%mod;
	rep(i,0,4){
		pw[i][0]=1;
		FOR(j,1,n)pw[i][j]=pw[i][j-1]*pw[i][1]%mod;
	}
	int base=0;
	FOR(i,1,n){
		int a,b,c;
		cin>>a>>b>>c;
		base^=a;
		b^=a;c^=a;
		T[0].val[b]++;T[1].val[c]++;T[2].val[b^c]++;
	}
	rep(i,0,3)T[i].solve();
	rep(i,0,m){
		int c0=0,c1=0,c2=0,c3=0;
		c1=T[0].dp[k][i][1];c2=T[1].dp[k][i][1];
		int tot=T[2].dp[k][i][1];
		c3=(c1+c2-tot)/2;c1-=c3;c2-=c3;
		c0=n-c1-c2-c3;
		fwt.val[i]=pw[0][c0]*pw[1][c1]%mod*pw[2][c2]%mod*pw[3][c3]%mod;
//		cout<<i<<' '<<c0<<' '<<c1<<' '<<c2<<' '<<c3<<'\n';
	}
	fwt.fwt(inv);
	rep(i,0,m)ans[i^base]=fwt.val[i];
	rep(i,0,m)cout<<ans[i]<<' ';
	RE 0;
}