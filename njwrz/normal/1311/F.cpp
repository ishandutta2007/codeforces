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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
P<int,int> p[200005];
int a[200005],n;
class bit{
	public:
	int s[200005];
	void up(int p,int x){
		while(p<=n){
			s[p]+=x;
			p+=p&-p;
		}
	}
	int get(int p){
		int re=0;
		while(p){
			re=re+s[p];
			p-=p&-p;
		}
		RE re;
	}
}tree1,tree2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>p[i].F;
	FOR(i,1,n)cin>>p[i].S,a[i]=p[i].S;
	sort(a+1,a+n+1);
	sort(p+1,p+n+1);
	int now,ans=0;
	FOR(i,1,n){
		now=lower_bound(a+1,a+n+1,p[i].S)-a;
		ans+=tree1.get(now)*p[i].F-tree2.get(now);
		tree1.up(now,1);tree2.up(now,p[i].F);
	}
	cout<<ans;
	RE 0;
}