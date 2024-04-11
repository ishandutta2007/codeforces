#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}

const int N=200;
int l, n, dfs_n, dfn[2*N], low[2*N], stack[2*N], *top=stack, scc_n, scc[2*N];
char t[27], c[2], s[N+1];
std::vector<int> edge[2*N];
void dfs(int x) {
	dfn[x]=low[x]=++dfs_n;
	*top++=x;
	for(int y: edge[x])
		if(dfn[y]==0) {
			dfs(y);
			cmin(low[x], low[y]);
		} else if(scc[y]==0) cmin(low[x], dfn[y]);
	if(dfn[x]==low[x]) {
		++scc_n;
		do {
			scc[*--top]=scc_n;
		} while(*top!=x);
	}
}
bool check() {
	dfs_n=scc_n=0;
	memset(dfn, 0, 2*n*sizeof(int));
	memset(scc, 0, 2*n*sizeof(int));
	for(int i=0; i<2*n; ++i) if(dfn[i]==0) dfs(i);
	for(int i=0; i<n; ++i) if(scc[2*i]==scc[2*i+1]) return false;
	return true;
}
void jie(int x) {
	if(x==n) {
		puts(s);
		exit(0);
	}
	int t=c[0]>c[1];
	edge[2*x+!t].push_back(2*x+t);
	if(check()) {
		s[x]=c[t];
	} else {
		edge[2*x+!t].pop_back();
		edge[2*x+t].push_back(2*x+!t);
		s[x]=c[!t];
	}
	jie(x+1);
}
void solve(int x) {
	if(x==n) {
		if(check()) {
			puts(s);
			exit(0);
		}
		return;
	}
	int cur=s[x]-'a';
	bool v[2]={};
	edge[2*x+!t[cur]].push_back(2*x+t[cur]);
	solve(x+1);
	edge[2*x+!t[cur]].pop_back();
	while(++cur<l) {
		if(v[t[cur]]) continue;
		v[t[cur]]=true;
		edge[2*x+!t[cur]].push_back(2*x+t[cur]);
		if(check()) {
			s[x]=cur+'a';
			jie(x+1);
			puts(s);
			exit(0);
		}
		edge[2*x+!t[cur]].pop_back();
	}
}
int main() {
	int m;
	assert(scanf("%s%d%d", t, &n, &m)==3);
	l=strlen(t);
	for(int i=0; i<l; ++i) t[i]=(t[i]=='C');
	for(int i=l; i--; ) c[t[i]]='a'+i;
	while(m--) {
		int pos1, pos2;
		char t1, t2;
		assert(scanf("%d %c%d %c", &pos1, &t1, &pos2, &t2)==4);
		--pos1, t1=(t1=='C'), --pos2, t2=(t2=='C');
		edge[2*pos1+t1].push_back(2*pos2+t2);
		edge[2*pos2+!t2].push_back(2*pos1+!t1);
	}
	assert(scanf("%s", s)==1);
	if(std::find(t, t+l, 0)==t+l) for(int i=0; i<n; ++i) edge[2*i].push_back(2*i+1);
	if(std::find(t, t+l, 1)==t+l) for(int i=0; i<n; ++i) edge[2*i+1].push_back(2*i);
	solve(0);
	puts("-1");
	return 0;
}