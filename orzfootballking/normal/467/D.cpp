#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
map<string,int> _map;
string s[300005];
P<P<int,int>,int> cnt[300005];P<int,int> c[300005];
bool vis[300005];
V<int> v[300005];int co,len;
void dfs(int p){
	if(vis[p])RE;
	c[p]=MP(co,len);vis[p]=1;
	for(auto u:v[p])dfs(u);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;cin>>n;
	FOR(i,1,n){
		cin>>s[i];
		rep(j,0,s[i].size()){
			if(s[i][j]<'a')s[i][j]+=' ';
			if(s[i][j]=='r')cnt[i].F.F++;
		}
		if(!_map.count(s[i]))_map[s[i]]=i;
		cnt[i].F.S=s[i].size();
		cnt[i].S=i;
	}
	cin>>m;string x,y;
	int q=n;
	FOR(i,1,m){
		cin>>x>>y;
		q++;
		rep(j,0,x.size()){
			if(x[j]<'a')x[j]+=' ';
			if(x[j]=='r')cnt[q].F.F++;
		}
		cnt[q].F.S=x.size();
		cnt[q].S=q;s[n+i*2-1]=x;
		if(!_map.count(x))_map[x]=q;
		q++;
		rep(j,0,y.size()){
			if(y[j]<'a')y[j]+=' ';
			if(y[j]=='r')cnt[q].F.F++;
		}
		cnt[q].S=q;s[q]=y;
		cnt[q].F.S=y.size();
		if(!_map.count(y))_map[y]=n+(i<<1);
		v[_map[y]].PB(_map[x]);
	}
	int sum=n+(m<<1);
	sort(cnt+1,cnt+sum+1);
	int t;
	FOR(i,1,sum)c[i]=MP(1000000000,1000000000);
	FOR(i,1,sum){
		co=cnt[i].F.F;len=cnt[i].F.S;
		dfs(_map[s[cnt[i].S]]);
	}
	ll ans1=0,ans2=0;
	P<int,int> ant;
	FOR(i,1,n){
		ant=c[_map[s[i]]];
		ans1+=ant.F;
		ans2+=ant.S;
	}
	cout<<ans1<<' '<<ans2;
	RE 0;
}