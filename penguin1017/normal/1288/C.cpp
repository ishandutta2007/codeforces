#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define lb(x) ((x)&(-x))
using namespace std;
const int N=2e6+9;
const ll mod=1e9+7;
vi g[N];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	int n,m;
	cin>>n>>m;
	ll ans=1,jie1=1,jie2=1;
	rep(i,1,n+2*m)ans=ans*i%mod;
	rep(i,1,n)jie1=jie1*i%mod;
	rep(i,1,2*m+1)jie2=jie2*i%mod;
//	cout<<ans<<' '<<jie1<<' '<<jie2<<"ans\n";
	ans=ans*quick(jie1,mod-2)%mod*quick(jie2,mod-2)%mod;
	cout<<ans;
}