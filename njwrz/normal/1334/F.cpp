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
int n;
class bit{
	public:
	int s[500005];
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
	void clear(){
		FILL(s,0);
	}
}tree;
int c[500005],a[500005],p[500005],b[500005];
int last[500005],dp[500005],maxi=1e17,rb[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>p[i];
	int m;
	cin>>m;
	FOR(i,1,m)cin>>b[i];
	FOR(i,2,m)last[b[i]]=b[i-1];
	int ans=0;
	FOR(i,1,n){
		c[i]=tree.get(a[i])-tree.get(last[a[i]]);
		if(p[i]<0){
			ans+=p[i];
			c[i]+=-p[i];
		}else tree.up(a[i],p[i]);
	}
	ans+=tree.get(n)-tree.get(b[m]);
	FOR(i,2,m+1)dp[i]=maxi;
	FOR(i,1,m)rb[b[i]]=i;
	FOR(i,1,n){
		if(!rb[a[i]])continue;
		gmin(dp[rb[a[i]]+1],dp[rb[a[i]]]+c[i]);
	}
	if(dp[m+1]==maxi){
		cout<<"NO\n";
	}else{
		cout<<"YES\n"<<ans+dp[m+1]<<'\n';
	}
	RE 0;
}