/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
using namespace std;
ll phi[10005][105], p2[320005], ans[320005];
int len, vis[320005];
 
void init(){
	len = 0;
	for(int i=2; i<320005; i++){
		if(!vis[i]){
			for(int j=i+i; j<320005; j+=i) vis[j]=1;
			p2[len++] = i;
			ans[i] = ans[i-1]+1;
			continue;
		}
		ans[i] = ans[i-1];
	}	
	for(int i=0; i<=10000; i++){
		phi[i][0] = (ll)i;
		for(int j=1; j<=100; j++){
			phi[i][j] = phi[i][j-1] - phi[i/p2[j-1]][j-1];
		}
	}
}
 
ll solve_phi(ll m, ll n){
	if(!n) return m;
	if(p2[n - 1] >= m) return 1;
	if(m<=10000 && n<=100) return phi[m][n];
	return solve_phi(m, n-1) - solve_phi(m/p2[n-1], n-1);
}
 
ll solve_p2(ll m){
	if(m < (ll)320005) return ans[m];
	
	ll y = (int)cbrt(m*1.0);
	ll n = ans[y];
	ll sum = solve_phi(m, n) + n -1;
	
	for(ll i=n; p2[i]*p2[i]<=m; i++) 
		sum = sum - solve_p2(m/p2[i])+solve_p2(p2[i])-1;
	return sum;
}
bool ss(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0)RE 0;
	}
	RE 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	ll t,ans=0;
	cin>>t;
	ll p=1;
	while(p*p*p<=t)p++;
	p--;
	ans=solve_p2(p);
	for(ll i=2;i*i<=t;i++)if(ss(i)){
		ans+=solve_p2(t/i)-solve_p2(i);
	} 
	cout<<ans;
	RE 0;
}