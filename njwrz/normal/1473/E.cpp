/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
#define PP P<P<int,int> ,P<bool,bool> >
using namespace std;
int d[200005][2][2];
V<P<int,int> > v[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int x,y,w;
	FOR(i,1,m){
		cin>>x>>y>>w;
		v[x].PB(MP(y,w));
		v[y].PB(MP(x,w));
	}
	priority_queue<PP,V<PP>,greater<PP> > q;
	q.emplace(MP(MP(0,1),MP(0,0)));
	FOR(i,1,n){
		FOR(j,0,1){
			FOR(k,0,1)d[i][j][k]=1e18;
		}
	}
	d[1][0][0]=0;
	while(!q.empty()){
		PP cur=q.top();q.pop();
		if(cur.F.F>d[cur.F.S][cur.S.F][cur.S.S])continue;
		for(auto u:v[cur.F.S]){
			if(!cur.S.F){
				if(d[u.F][1][cur.S.S]>cur.F.F+u.S+u.S){
					d[u.F][1][cur.S.S]=cur.F.F+u.S+u.S;
					q.emplace(MP(MP(d[u.F][1][cur.S.S],u.F),MP(1,cur.S.S)));
				}
			}
			if(!cur.S.S){
				if(d[u.F][cur.S.F][1]>cur.F.F){
					d[u.F][cur.S.F][1]=cur.F.F;
					q.emplace(MP(MP(d[u.F][cur.S.F][1],u.F),MP(cur.S.F,1)));
				}
			}
			if(d[u.F][cur.S.F][cur.S.S]>cur.F.F+u.S){
				d[u.F][cur.S.F][cur.S.S]=cur.F.F+u.S;
				q.emplace(MP(MP(d[u.F][cur.S.F][cur.S.S],u.F),cur.S));
			}
			if(!cur.S.S&&!cur.S.F){
				if(d[u.F][1][1]>cur.F.F+u.S){
					d[u.F][1][1]=cur.F.F+u.S;
					q.emplace(MP(MP(d[u.F][1][1],u.F),MP(1,1)));
				}
			}
		}
	} 
//	cout<<d[3][1][0]<<'\n';
	FOR(i,2,n){
		cout<<d[i][1][1]<<' ';
	}
	RE 0;
}