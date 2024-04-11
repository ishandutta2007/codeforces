#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=5e5+9;
int vis[N];
map<pii,int> id;
int sum[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		id.clear();
		int n,cnt=0;
		scanf("%d",&n);
		rep(i,0,n){
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			int x=c-a,y=d-b;
			int dd=__gcd(abs(x),abs(y));
			x/=dd,y/=dd;
			if(!id.count({x,y}))id[{x,y}]=++cnt,sum[cnt]=0;
			sum[id[{x,y}]]++;
		}
		ll ans=0;
		for(auto w:id){
			auto u=w.fi;
			int a=u.fi,b=u.se;
			if(id.count({a,b})&&id.count({-a,-b}))ans+=1ll*sum[id[{a,b}]]*sum[id[{-a,-b}]]; 
		}
		printf("%lld\n",ans>>1);
	}
}