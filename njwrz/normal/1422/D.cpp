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
int p[300005],d[300005];
bool vis[300005],used[300005];
V<P<int,int> > v[300005];
int x[100005],y[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>x[m+1]>>y[m+1]>>x[m+2]>>y[m+2];
	V<int> vx,vy;
	FOR(i,1,m){
		cin>>x[i]>>y[i];
	}
	FOR(i,1,m+2){
		vx.PB(x[i]);
		vy.PB(y[i]);
	}
	sort(ALL(vx));vx.erase(unique(ALL(vx)),vx.end());
	sort(ALL(vy));vy.erase(unique(ALL(vy)),vy.end());
	FOR(i,1,m+2){
		x[i]=lwb(ALL(vx),x[i])-vx.begin()+1;
		y[i]=lwb(ALL(vy),y[i])-vy.begin()+1;
	}
	int lx=vx.size(),ly=vy.size();
	int st=lx+ly+m+1,T=st+1;
	v[st].PB(MP(T,abs(vx[x[m+2]-1]-vx[x[m+1]-1])+abs(vy[y[m+2]-1]-vy[y[m+1]-1])));
	v[st].PB(MP(x[m+1],0));
	v[st].PB(MP(lx+y[m+1],0));
	FOR(i,1,m){
		v[lx+ly+i].PB(MP(T,abs(vx[x[m+2]-1]-vx[x[i]-1])+abs(vy[y[m+2]-1]-vy[y[i]-1])));
		v[x[i]].PB(MP(lx+ly+i,0));
		v[y[i]+lx].PB(MP(lx+ly+i,0));
		v[lx+ly+i].PB(MP(x[i],0));
		v[lx+ly+i].PB(MP(lx+y[i],0));
	}
	FOR(i,2,lx){
		v[i-1].PB(MP(i,vx[i-1]-vx[i-2]));
		v[i].PB(MP(i-1,vx[i-1]-vx[i-2]));
	}
	FOR(i,2,ly){
		v[i-1+lx].PB(MP(i+lx,vy[i-1]-vy[i-2]));
		v[i+lx].PB(MP(i-1+lx,vy[i-1]-vy[i-2]));
	}
	priority_queue<P<int,int> ,V<P<int,int> >,greater<P<int,int> > > q;
	q.emplace(MP(0,st));
	while(!q.empty()){
		P<int,int> cur=q.top();q.pop();
		if(used[cur.S])continue;
		used[cur.S]=1;
		for(auto u:v[cur.S])if(!used[u.F]){
			if(!vis[u.F]){
				vis[u.F]=1;
				d[u.F]=d[cur.S]+u.S;
			}else{
				gmin(d[u.F],d[cur.S]+u.S);
			}
			q.emplace(MP(d[u.F],u.F));
		}
	}
	cout<<d[T];
	RE 0;
}