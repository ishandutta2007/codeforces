#pragma GCC optimize("Ofast")
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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n; 
class bit{
	public:
	int s[500005];
	void up(int p,int x){
		while(p){
			gmax(s[p],x);
			p-=p&-p;
		}
	}
	int get(int p){
		int re=0;
		while(p<=n){
			gmax(re,s[p]);
			p+=p&-p;
		}
		RE re;
	}
	void clear(){
		FILL(s,0);
	}
}tree;
struct node{
	int a,b,c;
}; 
bool cmp(node x,node y){
	RE x.a>y.a||(x.a==y.a&&x.b<y.b);
}
node p[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>p[i].a;
	V<int> v;
	FOR(i,1,n)cin>>p[i].b,v.PB(p[i].b);
	FOR(i,1,n)cin>>p[i].c;
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	sort(p+1,p+n+1,cmp);
	FOR(i,1,n)p[i].b=lower_bound(ALL(v),p[i].b)-v.begin()+1;
	int ans=0;
	FOR(i,1,n){
		if(tree.get(p[i].b)>p[i].c)ans++;
		tree.up(p[i].b-1,p[i].c);
	} 
	cout<<ans<<'\n';
	RE 0;
}