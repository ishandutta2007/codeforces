#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int Mod=1e9+7;
const int N=1e6+50;

vector<int> E[N];

ll f[N][2];
ll g[N][2];

int deg[N];


void dfs(int x,int fr) {
	g[x][1]=deg[x];
	g[x][0]=1;
	f[x][1]=1;
	for(auto y: E[x]) {
		if(y==fr) continue;
		dfs(y,x);
		if(f[y][0]>f[y][1] || (f[y][0]==f[y][1] && g[y][0]<g[y][1])) {
			f[x][0]+=f[y][0],g[x][0]+=g[y][0];
		} else {
			f[x][0]+=f[y][1],g[x][0]+=g[y][1];
		}
		f[x][1]+=f[y][0],g[x][1]+=g[y][0];
	}
}
int a[N];
void rdfs(int x,int fr,int c) {
//	if(x==1) cerr << g[x][c] << endl;
	if(c==0) a[x]=1;
	else a[x]=deg[x];
	for(auto y: E[x]) {
		if(y==fr) continue;
		if(c==0) {
			if(f[y][0]>f[y][1] || (f[y][0]==f[y][1] && g[y][0]<g[y][1])) {
				rdfs(y,x,0);
			} else rdfs(y,x,1);
		} else rdfs(y,x,0);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	FOR(i,2,n) {
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
		++deg[x];
		++deg[y];
	}
	dfs(1,0);
	
	if(f[1][0]>f[1][1] || (f[1][0]==f[1][1] && g[1][0]<g[1][1])) rdfs(1,0,0);
	else rdfs(1,0,1);
	
	ll r=max(f[1][0],f[1][1]),s=0;
	if(n==2) ++r;
	FOR(i,1,n) s+=a[i];
	printf("%lld %lld\n",r,s);
//	if(f[1][0]>f[1][1] || (f[1][0]==f[1][1] && g[1][0]<g[1][1])) cerr << g[1][0] << endl;
//	else cerr << g[1][1] << endl;
	FOR(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}