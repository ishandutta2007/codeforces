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
V<int> v[2005];
int lst[2005],nxt[2005],n;
int dp[2005],dis[2005][2005],a[2005],num[2005],cnt;
P<int,int> from[2005]; 
void solve(int x,int y){
	int t=x+dis[x][y];
	if(t>n)t-=n;
	if(t==y){
		cout<<'+'<<dis[x][y]<<'\n';
	}else cout<<'-'<<dis[x][y]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int s;
	cin>>n>>s;
	int S=s;
	V<int> vs;
	FOR(i,1,n)cin>>a[i],vs.PB(a[i]);
	FOR(i,1,n){
		FOR(j,1,n){
			dis[i][j]=min(abs(i-j),n-abs(i-j));
		}
	}
	sort(ALL(vs));
	vs.erase(unique(ALL(vs)),vs.end());
	FOR(i,1,n)a[i]=lwb(ALL(vs),a[i])-vs.begin()+1,v[a[i]].PB(i);
	FOR(i,1,n)dp[i]=1e18;
	int ans;
	v[0].PB(s);
	FOR(i,1,n+1){
		if(v[i].empty()){
			ans=v[i-1].back();
			for(auto u:v[i-1]){
				if(dp[u]<dp[ans]){
					ans=u;
				}
			}
			break;
		}
		rep(j,0,v[i].size()){
			if(j){
				lst[v[i][j]]=v[i][j-1];
			}else lst[v[i][0]]=v[i][v[i].size()-1];
			if(j<v[i].size()-1){
				nxt[v[i][j]]=v[i][j+1];
			}else nxt[v[i][v[i].size()-1]]=v[i][0];
		}
			rep(_,0,v[i-1].size()){
				s=v[i-1][_];int add=i>1?dp[s]:0;
				rep(j,0,v[i].size()){
					int node=v[i][j];
					int now=dis[s][lst[node]];
					if(lst[node]<node){
						now+=n-(node-lst[node]);
					}else now+=lst[node]-node;
					if(now+add<dp[node]){
						dp[node]=now+add;
						from[node]=MP(i>1?s:0,0);
					}
					now=dis[s][nxt[node]];
					if(nxt[node]>node){
						now+=n-(nxt[node]-node);
					}else now+=node-nxt[node];
					if(now+add<dp[node]){
						dp[node]=now+add;
						from[node]=MP(i>1?s:0,1);
					}
				}
			}
	} 
	cout<<dp[ans]<<'\n';
	while(ans){
		num[++cnt]=ans;
		ans=from[ans].F;
	}
	reverse(num+1,num+cnt+1);
//	FOR(i,1,cnt)cout<<num[i]<<' ';cout<<'\n';
	s=S;
	FOR(i,1,cnt){
		if(from[num[i]].S==0){
			solve(s,lst[num[i]]);
			int now=lst[num[i]];
			while(now!=num[i]){
				int gto=lst[now];
				cout<<'-'<<((now-gto<0)?(n-(gto-now)):(now-gto))<<'\n';
				now=gto;
			}
		}else{
			solve(s,nxt[num[i]]);
			int now=nxt[num[i]];
			while(now!=num[i]){
				int gto=nxt[now];
				cout<<'+'<<((gto-now<0)?(n-(now-gto)):(gto-now))<<'\n';
				now=gto;
			}
		}
		s=num[i];
	}
	RE 0;
}