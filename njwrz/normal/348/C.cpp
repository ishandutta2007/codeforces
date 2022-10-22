/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int p_b[100005][350];
ll n,m,q,sum[100005],a[100005];
V<ll> g[100005],v[100005];
ll b[350],s[100005],cb,cs,add[350],tp[350],itb[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	FOR(i,1,n)cin>>a[i];
	ll B=350;
	FOR(i,1,m){
		ll len;
		cin>>len;
		ll x;
		FOR(j,1,len){
			cin>>x;
			g[x].PB(i);
			v[i].PB(x);
			sum[i]+=a[x];
		}
		if(len>B){
			b[++cb]=i;itb[i]=cb;
		}else s[++cs]=i;
	}
	FOR(i,1,cb){
		for(auto u:v[b[i]]){
			for(auto it:g[u]){
				p_b[it][i]++;
			}
		}
//		FOR(j,1,n){
//			cout<<p_b[j][i]<<' ';
//		}
//		cout<<'\n';
	}
	ll x,k,ans;
	FOR(i,1,q){
		char c;
		cin>>c;
		if(c=='+'){
			cin>>x>>k;
			if(v[x].size()<=B){
				FOR(j,1,cb){
					add[j]+=k*p_b[x][j];
				}
				for(auto u:v[x])a[u]+=k;
			}else{
				tp[itb[x]]+=k;
			}
		} else{
			cin>>x;
			if(v[x].size()<=B){
				ans=0;
				for(auto u:v[x]){
					ans+=a[u];
				}
				FOR(j,1,cb){
					ans+=p_b[x][j]*tp[j];
				}
				cout<<ans<<'\n';
			}else{
				ans=add[itb[x]];
//				cout<<add[itb[x]]<<' '<<x<<'\n';
				FOR(j,1,cb){
					ans+=p_b[b[j]][itb[x]]*tp[j];
				}
				cout<<ans+sum[x]<<'\n';
			}
		}
	}
	RE 0;
}