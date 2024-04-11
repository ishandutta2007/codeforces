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
V<P<int,int>> v[15];
int p[15][15][1<<14],dp[1<<14];
bool fv[15]; 
V<int> pv[15][15][1<<14],dpv[1<<14];
int a[200],b[200],lst[15],lstv[1<<14];
P<int,P<int,int>> ls[1<<14];
bool ch[15];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		a[i]=x;b[i]=y;
		v[x].PB(MP(y,i));
		v[y].PB(MP(x,i));
	}
	FOR(i,1,n){
		FOR(j,1,n){
			rep(k,0,1<<n){
				p[i][j][k]=1e9;
			}
		}
		p[i][i][1<<(i-1)]=0;
	}
	rep(nxt,1,1<<n){
		FOR(i,1,n)if(nxt&(1<<(i-1))){
			FOR(j,1,n)if(nxt&(1<<(j-1))){
				for(auto u:v[j])if(!(nxt&(1<<(u.F-1)))){
					int nx=(nxt|(1<<(u.F-1)));
					if(p[i][u.F][nx]>p[i][j][nxt]+1){
						p[i][u.F][nx]=p[i][j][nxt]+1;
						pv[i][u.F][nx]=pv[i][j][nxt];
						pv[i][u.F][nx].PB(u.S);
					}
				}
			}
		} 
	}
	rep(i,1,1<<n)dp[i]=1e9;
	FOR(i,1,n){
		dp[1<<(i-1)]=0;
	}
	rep(now,1,1<<n){
		if(dp[now]>m)continue;
		V<int> id;
		rep(j,0,n)if(now&(1<<j))id.PB(j+1);
		FILL(ch,0);
		FOR(i,1,n){
			for(auto u:v[i]){
				if(now&(1<<(u.F-1)))ch[i]=1,lst[i]=u.S;
			}
			V<int> ok;
			for(auto u:v[i]){
				if(now&(1<<u.F-1))ok.PB(u.S);
			}
			if(ok.size()>1){
				int to=(now|(1<<(i-1)));
				if(dp[now]+2<dp[to]){
					lstv[to]=now;ls[to]=MP(0,MP(0,0));
					dp[to]=dp[now]+2;
					dpv[to].clear();
					dpv[to].PB(ok.back());
					ok.pop_back();
					dpv[to].PB(ok.back());
				}
			}
		}
		int t=((1<<n)-1)^now,nxt=t;
		while(nxt){
			FOR(i,1,n)fv[i]=(nxt&(1<<(i-1))&&ch[i]);
			bool fin=0;
			FOR(i,1,n)if(fv[i]){
				FOR(j,i+1,n)if(fv[j]){
					if(p[i][j][nxt]+dp[now]+2<dp[now|nxt]){
						dp[now|nxt]=p[i][j][nxt]+dp[now]+2;
						lstv[now|nxt]=now;ls[now|nxt]=MP(nxt,MP(i,j));
						dpv[now|nxt].clear();
						dpv[now|nxt].PB(lst[i]);
						dpv[now|nxt].PB(lst[j]);
						fin=1;
					}
					if(fin)break;
				}
				if(fin)break;
			}
			nxt=(nxt-1)&t;
		}
	}
	cout<<dp[(1<<n)-1]<<'\n';
	int now=(1<<n)-1;
	while(now){
		for(auto u:pv[ls[now].S.F][ls[now].S.S][ls[now].F])
			cout<<a[u]<<' '<<b[u]<<'\n';
		for(auto u:dpv[now])cout<<a[u]<<' '<<b[u]<<'\n';
		now=lstv[now];
	}
	RE 0;
}