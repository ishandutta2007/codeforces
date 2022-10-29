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
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=1e9+7;
const ll Inf=1e6+2;
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a;
		if(res>Inf)return res;
		a=a*a;
		if(a>Inf)a=Inf;
		b>>=1;
	}
	return res;
}
ll quick2(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int k[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,p;
		scanf("%d%d",&n,&p);
		rep(i,0,n)scanf("%d",&k[i]);
		sort(k,k+n);
		ll last=k[n-1],d=0,ans=0;
		per(i,0,n){
			int v=k[i];
			d=d*quick(p,last-v);
			if(d>Inf)d=Inf;
			if(d){
				--d;
				ans-=quick2(p,v);
			}
			else{
				++d;
				ans+=quick2(p,v);
			}
			last=v;
		}
		ans=(ans%mod+mod)%mod;
		printf("%lld\n",ans); 
	}
}