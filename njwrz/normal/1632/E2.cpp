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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n;
V<int> v[300005];
int dis[300005],maxi[300005],val[300005];
void dfs(int x,int y){
	int m1=dis[x],m2=0; 
	for(auto u:v[x])if(u!=y){
		dis[u]=dis[x]+1;
		dfs(u,x);
		if(maxi[u]>m1){
			m2=m1;
			m1=maxi[u];
		}else if(maxi[u]>m2){
			m2=maxi[u];
		}
	}
	gmax(val[min(m1,m2)],m1+m2-2*dis[x]);
	maxi[x]=m1;
}
int tl,tr;
void solve(){
	cin>>n;
	FOR(i,1,n)v[i].clear();
	FOR(i,1,n+1)val[i]=0;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dis[1]=0;
	dfs(1,-1);
	for(int i=n;i>=1;i--)gmax(val[i],val[i+1]);
	int out=0;
	FOR(i,1,n){
		while((val[out+1]+1)/2+i>out)out++;
		cout<<min(out,maxi[1])<<' ';
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve(); 
	RE 0;
}