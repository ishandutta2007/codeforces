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
const int N=1e6+9;
const ll mod=998244353;
const ll Inf=1e18;
ll suf[N],pre[N][2];
int a[N];
int n,r1,r2,r3,d;
ll case1(int x){
	return 1ll*r1*x+r3;
}
ll case2(int x){
	return min(1ll*r2,1ll*r1*(x+1))+min(r1,r2);
}
int main(){
	scanf("%d%d%d%d%d",&n,&r1,&r2,&r3,&d);
	r1=min(r1,r3);
	rep(i,1,n+1)scanf("%d",&a[i]);
	pre[0][0]=-d;
	pre[0][1]=Inf;
	rep(i,1,n+1){
		ll val=min(pre[i-1][0],pre[i-1][1]);
		pre[i][0]=min(case1(a[i])+val+d,case2(a[i])+pre[i-1][1]+d);
		pre[i][1]=case2(a[i])+val+2*d+d;
		if(i==n)suf[n]=min(case1(a[i]),case2(a[i])+2*d);
		else suf[i]=min(case1(a[i]),case2(a[i]));
	}
	per(i,1,n)suf[i]+=suf[i+1]+2*d;
	suf[n+1]=-d;
	ll ans=Inf;
	rep(i,0,n+1){
		ll val=min(pre[i][0],pre[i][1]);
		ans=min(val+suf[i+1]+d,ans);
	} 
	printf("%lld\n",ans);
}