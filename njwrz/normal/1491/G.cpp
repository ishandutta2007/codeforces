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
V<int> v[200005]; 
int to[200005],it[200005],n;
bool vis[200005];
V<P<int,int> > ans; 
void merge(int x,int y){
	x=it[x];
	if(v[x].size()<=1||v[y].size()<=1)RE;
	ans.PB(MP(v[x].back(),v[y].back()));
	rep(i,0,v[x].size()-1){
		ans.PB(MP(v[y].back(),v[x][i]));
	}
	rep(i,0,v[y].size()-1){
		ans.PB(MP(v[x].back(),v[y][i]));
	}
	ans.PB(MP(v[x].back(),v[y].back()));
}
void solve(int x){
	if(v[x].size()==2){
		int t=-1;
		FOR(i,1,n){
			if(i!=v[x][0]&&i!=v[x][1]){
				t=i;break;
			}
		}
		rep(i,0,3){
			ans.PB(MP(v[x][i&1],t));
		}
	}else{
		int t3=v[x].back();
		v[x].pop_back();
		ans.PB(MP(v[x].back(),t3));
		rep(i,0,v[x].size()-2){
			ans.PB(MP(v[x].back(),v[x][i]));
		}
		int t2=v[x][v[x].size()-2],t1=v[x].back();
		swap(t2,t3);
//		cout<<t1<<' '<<t2<<' '<<t3<<'\n';
		ans.PB(MP(t2,t3));
		ans.PB(MP(t1,t3));
		ans.PB(MP(t1,t2));
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt;
	cin>>n;cnt=0;
	FOR(i,1,n)it[i]=i;
	FOR(i,1,n)cin>>to[i];
	FOR(i,1,n)if(!vis[i]){
		if(to[i]!=i){
			int t=to[i];
			++cnt;
			v[cnt].PB(i);
			while(t!=i){
				vis[t]=1;
				v[cnt].PB(t);
				t=to[t];
			}
		}
	}
	FOR(i,1,cnt){
		if(!(i&1))merge(i-1,i);
	}
	if(cnt&1){
		solve(cnt);
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
	RE 0;
}