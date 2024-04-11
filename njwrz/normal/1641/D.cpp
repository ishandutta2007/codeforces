#include<bits/stdc++.h>
#define ull unsigned long long
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
struct node{
	int a[5];
	int w;
}; 
node q[100005];
int n,m;
bool cmp(node x,node y){
	RE x.w<y.w;
}
int it;
V<P<int,int> > to[100005];
int cnt[100005*32];
void erase(int x){
	for(auto u:to[x])cnt[u.F]--;
}
int get(int x){
	int re=0;
	for(auto u:to[x])if(u.S&1){
		re+=cnt[u.F];
	}else re-=cnt[u.F];
	RE re;
}
mt19937_64 rnd(time(0));
unordered_map<int,ull> mp,mm;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		rep(j,0,m){
			cin>>q[i].a[j];
			if(!mp.count(q[i].a[j])){
				mp[q[i].a[j]]=rnd();
			}
		}
		sort(q[i].a,q[i].a+m);
		cin>>q[i].w;
	}
	sort(q+1,q+n+1,cmp);
	FOR(i,1,n){
		rep(j,1,1<<m){
			ull val=0;
			rep(k,0,m)if(j&(1<<k)){
				val^=mp[q[i].a[k]];
			}
			if(!mm.count(val))mm[val]=++it;
			to[i].PB(MP(mm[val],__builtin_popcount(j)));
		}
	}
	FOR(i,1,n){
		for(auto u:to[i])cnt[u.F]++;
	}
	int iter=n;
	int maxi=2147483647;
	int ans=maxi;
	FOR(i,1,n){
		while(iter&&get(i)<iter){
			erase(iter);
			iter--;
		}
		if(iter<n)gmin(ans,q[i].w+q[iter+1].w);
	}
	if(ans==maxi)cout<<-1;else cout<<ans;
	RE 0;
}