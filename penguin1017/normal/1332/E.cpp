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
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll a[2][2];
int main(){
	ll n,m,L,R;
	cin>>n>>m>>L>>R;
	ll ans=0;
	ll sum=R-L+1;
	ll tot=n*m;
	if(tot&1){
		ans=quick(sum,tot);
		cout<<ans;
		return 0;
	}
	ll even=tot/2,odd=tot-even;
	if(sum&1){
		ll res=quick(sum,even);
		if(res&1)res=res;
		else res+=mod;
		a[0][0]=res/2;
		a[0][1]=res-a[0][0];
		if(even%2==0)swap(a[0][0],a[0][1]);
		res=quick(sum,odd);
		if(res&1)res=res;
		else res+=mod;
		a[1][0]=res/2;
		a[1][1]=res-a[1][0];
		if(odd%2==0)swap(a[1][0],a[1][1]);
	}
	else{
		ll res=quick(sum,even);
		if(res&1)res+=mod;
		a[0][0]=res/2;
		a[0][1]=res-a[0][0];
		res=quick(sum,odd);
		if(res&1)res+=mod;
		a[1][0]=res/2;
		a[1][1]=res-a[1][0];
	}
	ans=a[0][0]*a[1][0]+a[0][1]*a[1][1];
	ans%=mod;
	cout<<ans;
}