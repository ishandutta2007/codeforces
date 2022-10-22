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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int p[205],n,lst[205];
int out[205],to[205];
struct DSU{
	int fa[205];
	void init(int n){
		FOR(i,1,n)fa[i]=i;
	}
	int get(int x){
		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
	}
	void merge(int x,int y){
		x=get(x);y=get(y);
		fa[x]=y;
	}
}T;
int ans[205];
void solve(){
	cin>>n;
	T.init(n);
	FOR(i,1,n)cin>>p[i],to[i]=p[i],lst[p[i]]=i,T.merge(i,p[i]),ans[i]=p[i];
	rep(i,1,n)if(T.get(i)!=T.get(i+1)){
		swap(ans[lst[i]],ans[lst[i+1]]);
		swap(lst[i],lst[i+1]);
		T.merge(i,i+1);
	} 
	int now=1;
	for(int i=n;i>=1;i--)out[i]=now,now=ans[now];
	int sum=0;
	rep(i,1,n)sum+=abs(out[i]-p[out[i+1]]);
	sum+=abs(out[n]-p[out[1]]);
//	cout<<sum<<'\n';
	FOR(i,1,n)cout<<out[i]<<' ';
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