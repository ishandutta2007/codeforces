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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int n;
V<int> v[500005];
int a[500005];
int vis[2];
bool found;
void dfs(int x,int y,int t){
	if(a[x])vis[t]++;
	for(auto u:v[x])if(u!=y)dfs(u,x,t^1);
}
void find(int x,int y,int t){
	if(a[x]&&!t){
		found=1;RE;
	}
	for(auto u:v[x])if(u!=y)find(u,x,t^1);
}
void solve(){
	cin>>n;
	FOR(i,1,n)v[i].clear();
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	FOR(i,1,n){
		char c;
		cin>>c;
		a[i]=c=='W';
	}
	if(n<=2){
		cout<<"Draw\n";RE;
	}
	FOR(i,1,n){
		if(a[i]+sz(v[i])>=4){
			cout<<"White\n";RE;
		}
	}
	FOR(i,1,n){
		for(auto u:v[i])if(a[i]&&a[u]){
			cout<<"White\n";RE;
		}
	}
	int cnt=0;
	FOR(i,1,n)cnt+=v[i].size()>2;
	FOR(i,1,n)if(sz(v[i])>=3){
		int cnt=0;
		for(auto u:v[i])cnt+=sz(v[u])>1;
		if(cnt>1){
			cout<<"White\n";RE;
		}
	}
	if(cnt>2){
		cout<<"White\n";RE;
	}
	if(n>=7&&(n&1)&&cnt==2){
		cout<<"White\n";RE;
	}
	FILL(vis,0);
	dfs(1,-1,0);
	if(vis[0]>1||vis[1]>1){
		cout<<"White\n";RE;
	}
	if(n>3){
		FOR(i,1,n)if(a[i]&&v[i].size()>1){
			cout<<"White\n";RE;
		}
	}
	found=0;
	FOR(i,1,n){
		for(auto u:v[i])if(sz(v[u])==3){
			find(i,u,0);
		}
	}
	if(found){
		cout<<"White\n";RE;
	}
	cout<<"Draw\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve(); 
	RE 0;
}