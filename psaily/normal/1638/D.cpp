#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=1005;
const int Mod=1e9+7;
int a[N][N];
int vis[N][N];
pii Q[N*N];
pair<pii,int> ans[N*N];
int f(int x,int y) {
	int w=0;
	FOR(i,x,x+1) FOR(j,y,y+1) {
		if(a[i][j]) {
			if(w==0) w=a[i][j];
			else if(w!=a[i][j]) return -1;
		}
	}
	return w;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	int l=1,r=0;
	FOR(i,1,n-1) FOR(j,1,m-1) {
		if(f(i,j)!=-1) Q[++r]=make_pair(i,j),vis[i][j]=1;
	}
	// cerr << " -- " << endl;
	int K=0;
	while(l<=r) {
		pii p=Q[l++];
		int x=p.fi,y=p.se;
		int c=f(x,y);
		if(c) ans[++K]=make_pair((pii){x,y},c);
		FOR(i,0,1) FOR(j,0,1) a[x+i][y+j]=0;
		FOR(i,x-1,x+1) FOR(j,y-1,y+1) if(i>=1 && i<=n-1 && j>=1 && j<=m-1 && f(i,j)!=-1 && !vis[i][j]) {
			Q[++r]=make_pair(i,j),vis[i][j]=1;
		} 
	}
	// cerr << " --- " << endl;
	if(r!=(n-1)*(m-1)) {
		puts("-1");
		return 0;
	}
	printf("%d\n",K);
	DOR(i,K,1) {
		printf("%d %d %d\n",ans[i].fi.fi,ans[i].fi.se,ans[i].se);
	}
	return 0;
}