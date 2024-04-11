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
map<P<int,int>,int> mp;
int n,m,a[300005],cnt[300005];
V<int> v[300005];
V<int> g[300005];
bool ff[300005];
int p[300005],len;
void solve(){
	cin>>n>>m;
	FOR(i,1,n)v[i].clear(),cnt[i]=0,g[i].clear(),g[i].PB(i);
	mp.clear();
	V<int> num;
	FOR(i,1,n){
		cin>>a[i];
		num.PB(a[i]);
	}
	sort(ALL(num));
	num.erase(unique(ALL(num)),num.end());
	FOR(i,1,n)a[i]=lwb(ALL(num),a[i])-num.begin()+1,cnt[a[i]]++;
	FOR(i,1,n)v[cnt[i]].PB(i);
	len=0;
	FOR(i,1,n)if(!v[i].empty()){
		sort(ALL(v[i]));
		reverse(ALL(v[i]));
		p[++len]=i;
	}
	int ans=0;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		x=lwb(ALL(num),x)-num.begin()+1;y=lwb(ALL(num),y)-num.begin()+1;
		g[x].PB(y);
		g[y].PB(x);
	}
	FOR(i,1,n)if(cnt[i]){
		for(auto u:g[i])ff[u]=1;
		FOR(j,1,len){
			rep(k,0,v[p[j]].size()){
				if(!ff[v[p[j]][k]]){
					gmax(ans,(p[j]+cnt[i])*(num[i-1]+num[v[p[j]][k]-1]));
					break;
				}
			}
		}
		for(auto u:g[i])ff[u]=0;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}