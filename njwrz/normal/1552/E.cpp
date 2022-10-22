#pragma GCC optimize(2)
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
int n,k,cnt[10005],a[10005];
V<int> v[105];
int ans[105];
P<int,int> out[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n*k){
		int x;
		cin>>x;a[i]=x;
		v[x].PB(i);
	}
	int now=0;
	int up=(n+k-2)/(k-1);
	FOR(i,1,n){
		V<P<int,P<int,int> > > in;
		FOR(j,1,n)if(!ans[j]){
			rep(k,0,v[j].size()-1)if(v[j][k]>now){
				in.PB(MP(v[j][k+1],MP(j,v[j][k])));break;
			}
		}
		sort(ALL(in));
		ans[in[0].S.F]=1;
		out[in[0].S.F]=MP(in[0].S.S,in[0].F);
		FOR(j,now+1,in[0].F)cnt[j]++;
		while(cnt[now+1]==up)now++;
	}
	FOR(i,1,n)cout<<out[i].F<<' '<<out[i].S<<'\n';
	RE 0;
}