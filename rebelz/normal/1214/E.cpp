#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
pii a[200005];
int dep[200005];
set<pii> s;
vector<int> adj[200005];
vector<pii> ans;

void dfs(int u){
	s.erase(s.find(mp(dep[u],u)));
	for(auto x:adj[u]) dfs(x);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=2*i-1;
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	for(int i=1;i<n;i++) ans.push_back(mp(a[i].se,a[i+1].se));
	for(int i=1;i<=n;i++) s.insert(mp(i,a[i].se)),dep[a[i].se]=i;
	for(int i=1;i<=n;i++){
		auto it=s.lower_bound(mp(a[i].fi+i-1,0));
		ans.push_back(mp(it->se,a[i].se+1));
		dep[a[i].se+1]=dep[it->se]+1,adj[it->se].push_back(a[i].se+1);
		s.insert(mp(dep[a[i].se+1],a[i].se+1));
		dfs(a[i].se);
	}
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);
	return 0;
}