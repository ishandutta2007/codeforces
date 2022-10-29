#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
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
const int N=1e5+9;
const ll mod=998244353;
const ll Inf=4e18;
int n;
ll a[N],b[N];
ll k;
ll get(ll c){
	if(c>0)return 0;
	ll l=0,r=1e9+1;
	while(l<r){
		ll mid=l+r>>1;
		if(-3*mid*mid+3*mid>=c)l=mid+1;
		else r=mid;
	} 
	return l-1;
}
ll check(ll K){
	ll res=0;
	rep(i,0,n)b[i]=min(a[i],get(K-a[i]+1)),res+=b[i];
	return res;
}
int main(){
	scanf("%d%lld",&n,&k);
	rep(i,0,n)scanf("%lld",&a[i]); 
	ll l=-Inf,r=Inf;
	while(l<r){
		ll mid=l+r>>1; 
		if(check(mid)>=k)l=mid+1;
		else r=mid;
	}
	--l;
	ll sum=check(l);
	//cout<<l<<' '<<sum<<"?\n";
	rep(i,0,n){
		if(sum>k&&3*(b[i])*(b[i])-3*(b[i])+l-a[i]+1==0){
			--b[i];--sum;
		}
	}
	rep(i,0,n)printf("%lld ",b[i]);
}