#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int N=1e7;
const ll mod=998244353;
const ll inv2=499122177;
pii q[N];
ll la[100],ra[100],lb[100],rb[100];
int cnt;
void add(ll l,ll r,ll val){
	int co=0;
	while(l<r){
		q[cnt++]={(l^val)<<co,((l^val)+1<<co)-1};
		q[cnt++]={(r^val)<<co,((r^val)+1<<co)-1};
		l=l+1>>1;
		r=r-1>>1;
		val>>=1;
		++co;
	}
	if(l==r)q[cnt++]={(l^val)<<co,((l^val)+1<<co)-1};
}
void add2(ll l0,ll r0,ll l1,ll r1){
	int co=0;
	while(l0<r0&&l1<r1){
		q[cnt++]={(l0^l1)<<co,((l0^l1)+1<<co)-1};
		q[cnt++]={(l0^r1)<<co,((l0^r1)+1<<co)-1};
		q[cnt++]={(r0^l1)<<co,((r0^l1)+1<<co)-1};
		q[cnt++]={(r0^r1)<<co,((r0^r1)+1<<co)-1};
		l0=l0+1>>1;
		r0=r0-1>>1;
		l1=l1+1>>1;
		r1=r1-1>>1;
		++co;
	}
	if(l0==r0||l1==r1){
		q[cnt++]={(l0^l1)<<co,((l0^l1)+1<<co)-1};
		q[cnt++]={(l0^r1)<<co,((l0^r1)+1<<co)-1};
		q[cnt++]={(r0^l1)<<co,((r0^l1)+1<<co)-1};
		q[cnt++]={(r0^r1)<<co,((r0^r1)+1<<co)-1};
	}
}
ll getsum(ll l,ll r){
	ll c1=(r-l+1)%mod;
	ll c2=(l+r)%mod;
	if(c1&1)c1+=mod;
	ll res2=c1*c2/2%mod;
	return res2;
} 
int main(){
	int a,b;
	scanf("%d",&a);
	rep(i,0,a)scanf("%lld%lld",&la[i],&ra[i]);
	scanf("%d",&b);
	rep(i,0,b)scanf("%lld%lld",&lb[i],&rb[i]);
	rep(i,0,a)rep(j,0,b){
		add(la[i],ra[i],lb[j]);
		add(la[i],ra[i],rb[j]);
		add(lb[j],rb[j],la[i]);
		add(lb[j],rb[j],ra[i]);
		add2(la[i],ra[i],lb[j],rb[j]);
	}
	sort(q,q+cnt);
	ll ans=0;
	rep(i,0,cnt){
		ll l=q[i].fi,r=q[i].se;
		while(i+1<cnt&&r>=q[i+1].fi){
			++i;
			r=max(r,q[i].se);
		}
		ans+=getsum(l,r);
	}
	ans%=mod;
	printf("%lld",ans);
}
/*
2
135131546
16541986116
165416
13561498416
2
1316
51984615
135
136546118616
*/