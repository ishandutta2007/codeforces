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
#define ALL(a) a.begin(),a.solve()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
const int N=(1<<20)+10;
int n,a[N],b[N],f[N];
V<int> g[N],ans;
struct node{
	int fi,se,to,id;
};
V<node> v[N];
void dfs(int id){
	f[id]=1;
	for(int u:g[id])if(!f[u])dfs(u);
}
bool check(int k){
	int cnt=0;
	rep(i,0,1<<k)if(g[i].size()&&!f[i]){
		cnt++;dfs(i);
	}
	return cnt==1;
}
void get(int x){
	while(!v[x].empty()){
		node u=v[x].back();v[x].pop_back();
		if(!f[u.id]){
			f[u.id]=1;get(u.to);
			ans.PB(u.se);
			ans.PB(u.fi);
		}
	}
}
void solve(int k){
	cout<<k<<'\n';
	FILL(f,0);
	int t=(1<<k)-1;
	FOR(i,1,n){
		int x=a[i]&t,y=b[i]&t;
		v[x].PB((node){i*2-1,i*2,y,i});
		v[y].PB((node){i*2,i*2-1,x,i});
	}
	get(a[1]&t);
	for(auto u:ans)cout<<u<<' ';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i]>>b[i];
	int l=0,r=20,ans1;
	while(l<=r){
		int mid=(l+r)>>1,t=(1<<mid)-1;
		FOR(i,0,t)f[i]=0,g[i].clear();
		FOR(i,1,n){
			int x=a[i]&t,y=b[i]&t;
			g[x].PB(y),g[y].PB(x);
		}
		int tf=0; 
		FOR(i,0,t){
			if(g[i].size()&1){
				tf=1;break;
			}
		}
		if(tf||!check(mid)){
			r=mid-1;
		}else{
			l=mid+1;
			ans1=mid;
		}
	}
	solve(ans1);
	return 0;
}