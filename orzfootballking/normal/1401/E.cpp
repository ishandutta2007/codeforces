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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
class bit{
	public:
	int s[1000005],m=1e6+2;
	void up(int p,int x){
		p++;
		while(p<=m){
			s[p]+=x;
			p+=p&-p;
		}
	}
	int get(int p){
		p++;
		int re=0;
		while(p){
			re=re+s[p];
			p-=p&-p;
		}
		RE re;
	}
	void clear(){
		FILL(s,0);
	}
}tree;
int c1,c2;
struct node{
	int x,l,r;
};
node p1[100005],p2[100005];
V<int> lv[1000005],rv[1000005],q[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>c2;
	int ans=1;
	FOR(i,1,c1){
		cin>>p1[i].x>>p1[i].l>>p1[i].r;
		ans+=p1[i].r-p1[i].l==1e6;
	}
	FOR(i,1,c2){
		cin>>p2[i].x>>p2[i].l>>p2[i].r;
		ans+=p2[i].r-p2[i].l==1e6;
	}
	FOR(i,1,c1){
		lv[p1[i].l].PB(i);
		rv[p1[i].r+1].PB(i);
	}
	FOR(i,1,c2)q[p2[i].x].PB(i);
	FOR(i,0,1e6){
		for(auto u:lv[i]){
			tree.up(p1[u].x,1);
		}
		for(auto u:rv[i]){
			tree.up(p1[u].x,-1);
		}
		for(auto u:q[i]){
			ans+=tree.get(p2[u].r)-tree.get(p2[u].l-1);
		}
	}
	cout<<ans;
	RE 0;
}