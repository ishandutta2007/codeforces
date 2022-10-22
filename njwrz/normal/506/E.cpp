#pragma GCC optimize("Ofast","inline","unroll-loops")
#include<bits/stdc++.h>
#define ll long long
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
const int mod=1e4+7;
string s;
char c[205];
int n;
struct matrix{
	int a[405][405];
};
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
matrix operator *(matrix x,matrix y){
	matrix re;
	FILL(re.a,0);
	FOR(i,0,n+n+1){
		FOR(k,0,n+n+1)if(x.a[i][k])FOR(j,0,n+n+1){
			add(re.a[i][j],x.a[i][k]*y.a[k][j]%mod);
		}
	}
	RE re;
}
matrix POW(matrix x,int y){
	matrix re;
	FILL(re.a,0);
	FOR(i,0,n+n+1)re.a[i][i]=1;
	while(y){
		if(y&1)re=re*x;
		x=x*x;
		y/=2;
	}
	RE re;
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
int dp[205][205][205];
int C[205][205];
int val[205],val2[205];
matrix now;
matrix base;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>s>>T;
	n=s.size();
	FOR(i,0,n){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	FOR(i,1,n)c[i]=s[i-1];
	dp[0][n+1][0]=1;
	FOR(l,0,n)for(int r=n+1;r>l+1;r--){
		FOR(len,0,n)if(dp[l][r][len]){
			if(c[l+1]==c[r-1])add(dp[l+1][r-1][len],dp[l][r][len]);
			else add(dp[l+1][r][len+1],dp[l][r][len]),add(dp[l][r-1][len+1],dp[l][r][len]);
		}
	}
	FOR(i,0,n+1)FOR(j,0,n){
		if(dp[i][i+1][j])add(val[j],dp[i][i+1][j]);
		if(dp[i][i][j])add(val[j],dp[i][i][j]);
	}
	int round=(n+T)/2;
	base.a[0][0]=1;base.a[0][(n+1)/2+n+1]=val[0];
	rep(i,0,n)now.a[i][i+1]=1;
	FOR(i,0,n)now.a[i][i]=24;
	for(int i=n;i>0;i--)now.a[i+n+1][i+n]=1;
	FOR(i,1,n)now.a[i+n+1][i+n+1]=25;
	now.a[n+1][n+1]=26;
	rep(i,0,n)if(val[i+1]){
		int t=(n-(i+1)+1)/2;
		now.a[i][t+n+1]=val[i+1];
	}
	base=base*POW(now,round);
	if((n+T)&1){
		int ans=base.a[0][n+1]*26%mod;
		FILL(now.a,0);FILL(base.a,0);
		FILL(val,0);
		rep(i,0,n)FOR(j,0,n)if(dp[i][i+2][j]){
			add(val[j],dp[i][i+2][j]);
		}
		rep(i,0,n)now.a[i][i+1]=1;
		FOR(i,0,n)now.a[i][i]=24;
		for(int i=n;i>0;i--)now.a[i+n+1][i+n]=1;
		FOR(i,1,n)now.a[i+n+1][i+n+1]=25;
		now.a[n+1][n+1]=25;
		base.a[0][0]=1;base.a[0][(n-1)/2+n+1]=val[0];
		rep(i,0,n)if(val[i+1]){
			int t=n+1+(n-i-2)/2;
			now.a[i][t]=val[i+1];
		}
		base=base*POW(now,round);
		add(ans,base.a[0][n+1]);
		cout<<ans;
	}else{
		cout<<base.a[0][n+1];
	}
	RE 0;
}