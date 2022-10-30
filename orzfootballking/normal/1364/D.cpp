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
int n,m;
struct dsu{
	int fa[100005];
	void init(){
		FOR(i,1,n)fa[i]=i;
	}
	int get(int x){
		if(fa[x]==x)RE x;
		else RE fa[x]=get(fa[x]);
	}
	bool up(int x,int y){
		x=get(x);y=get(y);
		if(x!=y){
			fa[x]=y;RE 1;
		}else RE 0;
	}
}T;
int a[200005],b[200005],d[100005],fa[100005][18];
bool f[200005];
V<int> g[100005];
void dfs(int p){
	for(auto u:g[p])if(u!=fa[p][0]){
		d[u]=d[p]+1;fa[u][0]=p;
		dfs(u);
	}
}
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	int t=d[x]-d[y];
	rep(i,0,18)if(t&(1<<i)){
		x=fa[x][i];
	}
	if(x==y)RE x;
	for(int i=17;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];y=fa[y][i];
		}
	}
	RE fa[x][0];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>m>>k;
	T.init();
	FOR(i,1,m){
		cin>>a[i]>>b[i];
		if(T.up(a[i],b[i])){
			g[a[i]].PB(b[i]);
			g[b[i]].PB(a[i]);f[i]=1;
		}
	}
	dfs(1);
	FOR(i,1,17){
		FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int mini=1e6,minp=-1;
	FOR(i,1,m){
		if(!f[i]){
			int t=lca(a[i],b[i]);
			int l=d[a[i]]+d[b[i]]-d[t]*2+1;
			if(l<mini){
				mini=l;minp=i;
			}
		}
	}
	if(minp==-1){
		int cnt=0;
		FOR(i,1,n){
			if(d[i]&1)cnt++;
		}
		cout<<"1\n";
		if(cnt>=(k/2)+(k&1)){
			cnt=(k/2)+(k&1);
			FOR(i,1,n)if(d[i]&1&&cnt){
				cnt--;cout<<i<<' ';
			}
		}else{
			cnt=(k/2)+(k&1);
			FOR(i,1,n)if((!(d[i]&1))&&cnt){
				cnt--;cout<<i<<' ';
			}
		}
		RE 0;
	}
	V<int> ans1,ans2;
	int x=a[minp],y=b[minp],t=lca(x,y);
	while(x!=t){
		ans1.PB(x);x=fa[x][0];
	}
	ans2.PB(y);
	while(y!=t){
		y=fa[y][0];ans2.PB(y);
	}
	reverse(ALL(ans1));
	for(auto u:ans1)ans2.PB(u);
	if(ans2.size()>k){
		cout<<"1\n";
		int cnt=(k/2)+(k&1);
		for(int i=0;i<ans2.size()&&cnt;i+=2){
			cout<<ans2[i]<<' ';cnt--;
		}
	}else{
		cout<<"2\n";
		cout<<ans2.size()<<'\n';
		for(auto u:ans2)cout<<u<<' ';
	}
	RE 0;
}