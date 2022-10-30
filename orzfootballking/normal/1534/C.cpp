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
int a[400005],b[400005],fa[400005];
int getfa(int x){
	if(x==fa[x])RE x;
	else RE fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	x=getfa(x);y=getfa(y);
	fa[x]=y;
}
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	FOR(i,1,n){
		if(a[i]==b[i]){
			cout<<0<<'\n';RE ;
		}
	}
	FOR(i,1,n)fa[i]=i;
	int cnt=0,ans=1;
	FOR(i,1,n)merge(a[i],b[i]);
	FOR(i,1,n)cnt+=getfa(i)==i;
	FOR(i,1,cnt)ans=ans*2%1000000007;
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}