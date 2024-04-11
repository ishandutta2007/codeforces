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
int a[200005],n;
int maxi[200005],mod=1e9+7;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
struct bit{
	int s[200005];
	void update(int x,int y){
		while(x<=n){
			add(s[x],y);
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			add(re,s[x]);
			x-=x&-x;
		}
		RE re;
	}
	void clear(int x){
		FOR(i,1,x)s[i]=0;
	}
}T,T2;
P<int,int> p[200005];
V<int> it[200005];
int pos[200005],len;
void solve(){
	V<int> v;
	cin>>n;
	FOR(i,1,n)cin>>a[i],v.PB(a[i]),it[i].clear();
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n)a[i]=lwb(ALL(v),a[i])-v.begin()+1;
	maxi[n+1]=0;
	for(int i=n;i>=1;i--)maxi[i]=max(maxi[i+1],a[i]);
	T.clear(n);T2.clear(n);
	int ans=0;
	FOR(i,1,n){
		p[i].F=T.get(a[i]-1);
		p[i].S=T2.get(a[i]-1);
		add(p[i].F,1);
		add(p[i].S,p[i].F);
		add(ans,p[i].S);
		T.update(a[i],p[i].F);
		T2.update(a[i],p[i].S);
	}
//	cout<<ans<<'\n';
	T.clear(n);T2.clear(n);
	FOR(i,1,n){
		if(maxi[i+1]<maxi[i]||a[i]==maxi[i+1]){
			len=0;
			rep(j,maxi[i+1],maxi[i]){
				for(auto u:it[j])pos[++len]=u;
			}
			sort(pos+1,pos+len+1);
			V<P<int,int> > use;
			FOR(j,1,len){
				int now=T.get(a[pos[j]]-1);
				add(now,p[pos[j]].F);
				T.update(a[pos[j]],now);
				use.PB(MP(a[pos[j]],now));
			}
			add(ans,mod-T.get(a[i]-1));
			add(ans,mod-p[i].F);
			for(auto u:use)T.update(u.F,mod-u.S);
		}
		it[a[i]].PB(i);
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