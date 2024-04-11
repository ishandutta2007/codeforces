#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
using namespace std;

int mu,a[20000009]; ll ans;
void gao(int x,int y){
	if (x==mu || y==mu || x>=y) return;
	ans=min(ans,(ll)x*y);
}
int main(){
	int cas; scanf("%d",&cas);
	while (cas--){
		int n,l,r; unsigned int x,y,z,b1,b2;
		scanf("%d%d%d%u%u%u%u%u",&n,&l,&r,&x,&y,&z,&b1,&b2);
		int i; mu=2100000000;
		int t1=mu,t2=mu,t3=mu,t4=mu,t5=mu;
		ans=(ll)mu*mu;
		unsigned int u,v,t;
		for (i=1; i<=n; i++){
			if (i==1) t=b1; else if (i==2) t=b2; else t=u*x+v*y+z;
			int now=(ll)t%((ll)r-(ll)l+1)+l;
			gao(t1,now); gao(t2,now); gao(t3,now); gao(t4,now); gao(t5,now);
			a[i]=now;
			if (now<0){
				if (t1==mu || now<t1) t1=now;
				if (t2==mu || now>t2) t2=now;	
			} else if (now>0){
				if (t3==mu || now<t3) t3=now;
				if (t4==mu || now>t4) t4=now;
			} else t5=0;
			u=v; v=t;
		}
		t1=t2=t3=t4=t5=mu;
		for (i=n; i; i--){
			int now=a[i];
			gao(now,t1); gao(now,t2); gao(now,t3); gao(now,t4); gao(now,t5);
			if (now<0){
				if (t1==mu || now<t1) t1=now;
				if (t2==mu || now>t2) t2=now;	
			} else if (now>0){
				if (t3==mu || now<t3) t3=now;
				if (t4==mu || now>t4) t4=now;
			} else t5=0;
		}
		if (ans==(ll)mu*mu) puts("IMPOSSIBLE"); else printf("%lld\n",ans);	
	}
	return 0;
}