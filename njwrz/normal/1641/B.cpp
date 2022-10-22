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
int a[1005];
int n;
int cnt[505];
int it[1005];
V<P<int,int> > op;
int len;
int ans[505],tl=0;
void add(int x,int y){
	len+=2;
	x++;
	for(int i=len;i>=x+2;i--){
		a[i]=a[i-2];
		it[i]=it[i-2]+2;
	}
	a[x]=y;it[x]=it[x-1]+1;
	a[x+1]=y;it[x+1]=it[x]+1;
	op.PB(MP(it[x]-1,y));
	FOR(i,1,tl)if(ans[i]>it[x-1])ans[i]+=2;
}
void erase(int x,int y){
	tl++;
	for(int i=tl;i>1;i--)ans[i]=ans[i-1];
	ans[1]=it[y];
	len-=y;
	FOR(i,1,len)a[i]=a[i+y],it[i]=it[i+y];
}
void solve(){
	cin>>n;
	V<int> v;
	FOR(i,1,n)cin>>a[i],v.PB(a[i]);
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n){
		a[i]=lwb(ALL(v),a[i])-v.begin();
	}
	FOR(i,0,n)cnt[i]=0;
	FOR(i,1,n)cnt[a[i]]++;
	FOR(i,0,n){
		if(cnt[i]&1){
			cout<<-1<<'\n';RE ;
		}
	}
	FOR(i,1,n)it[i]=i;
	op.clear();
	len=n;
	tl=0;
	while(len){
		int to=-1;
		FOR(i,2,len){
			if(a[i]==a[1]){
				to=i;break;
			}
		}
		rep(i,2,to){
			add(to+i-2,a[i]);
		}
//		cout<<len<<' ';
		erase(1,(to-1)*2);
//		cout<<to<<' '<<len<<'\n';
//		FOR(i,1,len)cout<<a[i]<<' ';
//		cout<<'\n';
	}
	cout<<op.size()<<'\n';
	for(auto u:op)cout<<u.F<<' '<<v[u.S]<<'\n';
	cout<<tl<<'\n';
	sort(ans+1,ans+tl+1);
	FOR(i,1,tl)cout<<ans[i]-ans[i-1]<<' ';
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