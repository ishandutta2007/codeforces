#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second 
#define mp make_pair
#define all(x) x.begin(),x.end()
#define lb(x) ((x)&(-x))
#define ll long long 
using namespace std;
const int N=2e6+9;
vector<pii> f;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll p,q;
		scanf("%lld%lld",&p,&q);
		if(p%q){
			printf("%lld\n",p);
			continue;
		} 
		for(int i=2;i*i<=q;++i){
			if(q%i==0){
				int v=i,s=1;
				while(q%i==0){
					s*=i;
					q/=i;
				}
				f.pb(mp(v,s));
			}
		}
		if(q>1)f.pb(mp(q,q));
		ll ans=0;
		for(auto w:f){
			int d=w.se;
			ll P=p;
			while(P%d==0){
				P/=w.fi;
			}
		//	cout<<P<<' '<<d<<' '<<w.fi<<"check\n";
			ans=max(ans,P);
		}
		printf("%lld\n",ans);
		f.clear();
		
	}
}