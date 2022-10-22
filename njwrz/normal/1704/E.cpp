#include<bits/stdc++.h>
#define int long long
#define lb long double
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
const int mod=998244353;
int a[1005],b[1005];
int n,m;int cnt[1005];
V<int> v[1005];
int it[1005],in[1005],len;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
bool big[1005];
void solve(){
	cin>>n>>m;
	FOR(i,1,n)cnt[i]=0,v[i].clear();
	FOR(i,1,n)cin>>a[i],big[i]=0;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		cnt[x]++;
		in[y]++;
	}
	queue<int> q;
	FOR(i,1,n)if(!in[i])q.emplace(i);
	len=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		it[++len]=x;
		for(auto u:v[x])if(--in[u]==0)q.emplace(u);
	}
	int ans=0;
	FOR(i,0,n){
		bool f=0;
		FOR(j,1,n){
			if(a[j]){
				f=1;
			}
			if(a[it[j]]>n)big[j]=1;
		}
		if(!f){
			cout<<i<<'\n';RE ;
		}
		for(int j=n;j>=1;j--)if(a[it[j]]||big[j]){
			add(a[it[j]],mod-1);
			for(auto u:v[it[j]])add(a[u],1);
		}
		ans++;
	}
	FOR(i,1,n){
		for(auto u:v[it[i]]){
			add(a[u],a[it[i]]);
		}
	}
	FOR(i,1,n)if(!cnt[i]){
		cout<<(a[i]+ans)%mod<<'\n';break;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}