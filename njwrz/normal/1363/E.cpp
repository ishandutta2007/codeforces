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
int n,ans;
int a[200005],b[200005],c[200005],mini[200005];
V<int> v[200005];
void get(int p,int fa){
	for(auto u:v[p])if(u!=fa){
		mini[u]=min(a[u],mini[p]);get(u,p);
	}
}
P<int,int> dfs(int p,int fa){
	P<int,int> re=MP(0,0);
	if(b[p]!=c[p]){
		if(b[p])re.S++;else re.F++;
	}
	for(auto u:v[p])if(u!=fa){
		P<int,int> tp=dfs(u,p);
		re.F+=tp.F;re.S+=tp.S;
	}
	int tm=min(re.F,re.S);
	ans+=tm*mini[p]*2;
	re.F-=tm;re.S-=tm;
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i]>>b[i]>>c[i];
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);v[y].PB(x);
	}
	mini[1]=a[1];
	get(1,-1);
	P<int,int> t=dfs(1,-1);
	if(t!=MP(0ll,0ll)){
		cout<<-1;RE 0;
	}
	cout<<ans;
	RE 0;
}