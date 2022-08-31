#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q;
int du[100005];
vector<int> adj[100005],g[100005];

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].push_back(y); adj[y].push_back(x);
		du[x]++,du[y]++;
	}
	for(int i=1;i<=n;i++) for(auto v:adj[i]) if(v>i) g[i].push_back(v);
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=1ll*g[i].size()*(du[i]-g[i].size());
	printf("%lld\n",ans);
	q=readint();
	while(q--){
		x=readint();
		ans-=1ll*g[x].size()*(du[x]-g[x].size());
		for(auto v:g[x]){
			ans-=1ll*g[v].size()*(du[v]-g[v].size());
			g[v].push_back(x);
			ans+=1ll*g[v].size()*(du[v]-g[v].size());
		}
		g[x].clear();
		printf("%lld\n",ans);
	}
	return 0;
}