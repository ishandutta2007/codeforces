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
using namespace std;
int ans[10005][1005],n,m,d[10005];
bool f[10005][1005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;m--;
	FOR(i,0,m)cin>>d[i];
	sort(d,d+m+1);
	FILL(ans,-1);
	ans[0][0]=0;
	deque<P<int,int>> q;
	q.PB(MP(0,0));
	int g,r;
	cin>>g>>r;
	P<int,int> cur;
	int t,cost,to;
	while(!q.empty()){
		cur=q.front();
		q.pop_front();
		if(f[cur.F][cur.S])continue;
		f[cur.F][cur.S]=1;
		if(cur.F){
			t=d[cur.F]-d[cur.F-1];
			cost=cur.S<t;to=cur.S-t;
			if(!cur.S)to+=g;
			if(!f[cur.F-1][to]&&to>=0){
				if(ans[cur.F-1][to]==-1||ans[cur.F-1][to]>ans[cur.F][cur.S]+cost)
					ans[cur.F-1][to]=ans[cur.F][cur.S]+cost;
				if(cost)q.PB(MP(cur.F-1,to));else q.PF(MP(cur.F-1,to));
			}
		}
		if(cur.F<m){
			t=d[cur.F+1]-d[cur.F];
			cost=cur.S<t;to=cur.S-t;
			if(!cur.S)to+=g;
			if(!f[cur.F+1][to]&&to>=0){
				if(ans[cur.F+1][to]==-1||ans[cur.F+1][to]>ans[cur.F][cur.S]+cost)
					ans[cur.F+1][to]=ans[cur.F][cur.S]+cost;
				if(cost)q.PB(MP(cur.F+1,to));else q.PF(MP(cur.F+1,to));
			}
		}
	}
	int maxi=1e17,pp=maxi;
	rep(i,0,g){
		if(ans[m][i]!=-1)gmin(maxi,(ans[m][i]-1)*(g+r)+g-i);
	}
	if(maxi==pp)cout<<-1;
	else cout<<maxi;
	RE 0;
}