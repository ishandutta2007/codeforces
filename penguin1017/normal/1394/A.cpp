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
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
ll p1[N],p2[N];
int cnt1,cnt2;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	ll n,d,m;
	scanf("%lld%lld%lld",&n,&d,&m);
	++d;
	rep(i,0,n){
		ll x;
		scanf("%lld",&x);
		if(x>m)p2[++cnt2]=x;
		else p1[++cnt1]=x;
	}
	sort(p1+1,p1+cnt1+1,cmp);
	sort(p2+1,p2+cnt2+1,cmp);
	rep(i,1,cnt1+1)p1[i]+=p1[i-1];
	rep(i,1,cnt2+1)p2[i]+=p2[i-1];
	ll ans=0;
	rep(i,0,cnt1+1){
		int x=n-i;
		x=x/d+((x%d)?1:0);
		ans=max(ans,p1[i]+p2[x]);
	}
	printf("%lld",ans);
}