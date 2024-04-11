#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
const int mod = 2520;
ll dp[20][55][mod+50];
int a[20];
int cnt = 0;
int ha[mod+50];
ll gcd(ll a,ll b){
	if(a < b) swap(a,b);
	ll t;
	while(a%b!=0){
		t = a%b;a = b;b = t;
	}return b;
}
ll dfs(int pos,int res,int lcm,int lim){
	if(pos == 0) return res%lcm == 0;
	if(!lim && dp[pos][ha[lcm]][res]!=-1) return dp[pos][ha[lcm]][res];
	int up = lim?a[pos]:9;
	ll ans = 0;
	for(int i = 0;i <= up;++i){
		ans += dfs(pos-1,(res*10+i)%mod,i?lcm*i/gcd(lcm,i):lcm,lim && i==up);
	}
	if(!lim) dp[pos][ha[lcm]][res] = ans;
	return ans;
}
ll sol(ll x){
	cnt = 0;
	while(x) a[++cnt] = x%10,x/=10;
	return dfs(cnt,0,1,1);
}
int main(){
	memset(dp,-1,sizeof dp);
	int t = 0;
	for(int i = 1;i < mod ;++i) if(mod%i == 0) ha[i] = ++t;
	int T;cin>>T;
	ll l,r;
	while(T--){
		cin>>l>>r;
		cout<<sol(r) - sol(l-1)<<endl;
	}
}