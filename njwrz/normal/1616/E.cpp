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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
char s[100005],t[100005];
int sum[200005],n;
void update(int x,int y){
	while(x<=n+n){
		sum[x]+=y;
		x+=x&-x; 
	}
}
int get(int x){
	int re=0;
	while(x){
		re+=sum[x];
		x-=x&-x;
	}
	RE re;
}
set<int> it[26];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>s[i];
	FOR(i,1,n)cin>>t[i];
	ll ans=1e18,nows=0;
	FOR(i,1,n+n)sum[i]=0;
	FOR(i,n+1,n+n)update(i,1);
	rep(i,0,26)it[i].clear();
	FOR(i,1,n)it[s[i]-'a'].emplace(n+i);
	FOR(i,1,n){
		int cc=t[i]-'a';
		rep(j,0,cc)if(!it[j].empty()){
			int pos=*it[j].begin();
			gmin(ans,nows+get(pos)-1);
		}
		if(it[cc].empty())break;
		nows+=get(*it[cc].begin())-1;
		update(*it[cc].begin(),-1);
		it[cc].erase(it[cc].begin());
	} 
	if(ans>10000000000000000ll){
		cout<<-1<<'\n';
	}else cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}