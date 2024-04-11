#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=2e5+50;
const int Mod=1e9+7;
vector<pii> E[N];
int col[N];
int res=1;
void dfs(int x,int c) {
	col[x]=c;
	for(auto e: E[x]) {
		if(!col[e.fi]) dfs(e.fi,c^3);
		else if(col[e.fi]==c) res=0;
	}
}
int Q[N],deg[N],ans[N];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,1,m) {
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		E[x].push_back(make_pair(y,t));
		E[y].push_back(make_pair(x,t));
	}
	FOR(i,1,n) if(!col[i]) dfs(i,1);
	if(!res) {
		puts("NO");
		return 0;
	}
	FOR(i,1,n) {
		for(auto &e: E[i]) {
			if(e.se!=col[i]) {
				++deg[e.fi];
				e.se=1;
			} else e.se=0;
		}
	}
	int l=1,r=0;
	FOR(i,1,n) if(deg[i]==0) Q[++r]=i;
	while(l<=r) {
		ans[Q[l]]=l;
		int x=Q[l++];
		for(auto e: E[x]) if(e.se) {
			if(!(--deg[e.fi])) Q[++r]=e.fi;
		}
	}
	if(r<n) {
		puts("NO");
		return 0;
	}
	puts("YES");
	FOR(i,1,n) printf("%c %d\n"," RL"[col[i]],ans[i]);
	return 0;
}