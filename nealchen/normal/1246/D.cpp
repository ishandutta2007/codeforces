#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
const int N=1e5;
int n, p[N], dep[N], prefer[N];
std::vector<int> ch[N], ans, op;
void dfs(int u) {
	if(u) {
		int cnt=dep[ans.back()]-dep[p[u]];
		while(cnt--) op.push_back(u);
	}
	ans.push_back(u);
	for(int v: ch[u]) if(v!=prefer[u]) dfs(v);
	if(prefer[u]) dfs(prefer[u]);
}
int main() {
	n=rd();
	for(int i=1; i<n; ++i) {
		ch[p[i]=rd()].push_back(i);
		dep[i]=dep[p[i]]+1;
	}
	int max_id=std::max_element(dep, dep+n)-dep;
	for(int i=max_id; i; i=p[i]) prefer[p[i]]=i;
	dfs(0);
	for(int i: ans) printf("%d ", i);
	printf("\n%d\n", (int)op.size());
	for(int i: op) printf("%d ", i);
	puts("");
	return 0;
}