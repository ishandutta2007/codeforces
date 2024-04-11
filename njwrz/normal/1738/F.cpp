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
int siz[1005];
int it[1005],n;
int vis[1005];
bool cmp(int x,int y){
	RE siz[x]>siz[y];
}
struct DSU{
	int fa[1005],siz[1005];
	void init(int n){
		FOR(i,1,n)fa[i]=i,siz[i]=1;
	}
	int get(int x){
		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
	}
	void merge(int x,int y){
		x=get(x);y=get(y);
		if(x!=y)siz[y]+=siz[x];
		fa[x]=y;
	}
}T;
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>siz[i],vis[i]=0;
	FOR(i,1,n)it[i]=i;
	sort(it+1,it+n+1,cmp);
	T.init(n); 
	FOR(i,1,n)if(!vis[it[i]]){
		FOR(j,1,siz[it[i]]){
			cout<<"?"<<' '<<it[i]<<'\n';
			cout.flush();
			int x;
			cin>>x;vis[x]=1;
			if(T.siz[T.get(x)]==1){
				T.merge(x,it[i]);
			}else{
				T.merge(x,it[i]);
				break;
			}
		}
	}
	cout<<"!"<<' ';
	FOR(i,1,n)cout<<T.get(i)<<' ';
	cout<<'\n';cout.flush();
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}