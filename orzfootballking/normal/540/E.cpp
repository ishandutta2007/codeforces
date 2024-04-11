#pragma GCC optimize("Ofast")
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
using namespace std;
V<int> un,seq;
int a[100005],b[100005],n;
class bit{
	public:
	int s[200005];
	void up(int p,int x){
		while(p){
			s[p]+=x;
			p-=p&-p;
		}
	}
	int get(int p){
		int re=0;
		while(p<=n*2){
			re=re+s[p];
			p+=p&-p;
		}
		RE re;
	}
	void clear(){
		FILL(s,0);
	}
}tree;
map<int,int> m;
int bet(int x,int y){
	if(x>y)RE 0;
	RE upb(ALL(un),y)-lwb(ALL(un),x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i]>>b[i];
		un.PB(a[i]);un.PB(b[i]); 
	}
	sort(ALL(un));
	un.erase(unique(ALL(un)),un.end());
	seq=un;
	for(auto u:seq)m[u]=u;
	FOR(i,1,n){
		a[i]=lwb(ALL(un),a[i])-un.begin();
		b[i]=lwb(ALL(un),b[i])-un.begin();
		swap(seq[a[i]],seq[b[i]]);
		m[seq[a[i]]]=un[a[i]];
		m[seq[b[i]]]=un[b[i]];
	}
	int ans=0;
	for(auto u:m){
		if(u.F>u.S){
			ans+=u.F-u.S-1-bet(u.S+1,u.F-1);
		}else if(u.F<u.S){
			ans+=u.S-u.F-1-bet(u.F+1,u.S-1);
		}
	}
	int t;
	for(auto u:seq){
		t=lwb(ALL(un),u)-un.begin()+1;
		ans+=tree.get(t);
		tree.up(t,1);
	}
	cout<<ans;
	RE 0;
}