#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
const int p=131;
int dp[2][32][N];
char s[N],t[N];
ll hs[N],ht[N],mul[N];
void upd(int &a,int b){
	if(a<b)a=b;
}
ll gt(int l,int r){
	ll res=(ht[r]-mul[r-l]*ht[l])%mod;
	if(res<0)res+=mod;
	return res;
}
ll gs(int l,int r){
	ll res=(hs[r]-mul[r-l]*hs[l])%mod;
	if(res<0)res+=mod;
	return res;
}
int main(){
	int n,m,x;
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d%s%d",&m,t+1,&x);
	mul[0]=1;
	rep(i,1,N)mul[i]=mul[i-1]*p%mod;
	rep(i,1,n+1)hs[i]=(hs[i-1]*p+s[i])%mod;
	rep(i,1,m+1)ht[i]=(ht[i-1]*p+t[i])%mod;
	rep(i,1,n+1){
		int pos=1;
		rep(j,0,x+1){
			if(t[dp[0][j][i-1]+1]==s[i]){
				upd(dp[1][j+1][i],dp[0][j][i-1]+1);
				pos=j+1;
			}
			upd(dp[0][j][i],dp[0][j][i-1]);
		}
		per(j,1,pos){
			int e=dp[1][j+1][i],b=dp[0][j-1][i-1];
		//	cout<<i<<' '<<e<<' '<<b<<"comein\n";
			int d=e-b;
			if(dp[1][j-1][i-d]<b&&dp[0][j-1][i-d]<b)continue;
		//	cout<<gt(b,e)<<' '<<gs(i-d,i)<<"ok\n";
			if(gt(b,e)==gs(i-d,i)){
				upd(dp[1][j][i],e); 
			} 
		}
		rep(j,1,x+1){
			if(t[dp[1][j][i-1]+1]==s[i]){
				upd(dp[1][j][i],dp[1][j][i-1]+1);
			}
			upd(dp[0][j][i],dp[1][j][i-1]);
		//	cout<<i<<' '<<j<<' '<<dp[1][j][i]<<"dp\n";
		//	cout<<i<<' '<<j<<' '<<dp[0][j][i]<<"dp2\n";
		}
	}
	rep(i,0,2)rep(j,1,x+1)rep(k,1,n+1){
		if(dp[i][j][k]==m){
			cout<<"YES\n";
			return 0;
		}
	}
	printf("NO\n");
}
/*
7
abababc
5
ababc
1
*/