#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}

const int N=1e5+5;
int next[N], prev[N], head[N];
char s[N];
std::vector<int> end[2], qaq[2][2];
void cat(int u, int v) {
	next[u]=head[v];
	prev[head[v]]=u;
	head[v]=head[u];
}
int main() {
	int n, last;
	std::cin>>s+1;
	n=strlen(s+1);
	for(int i=1; i<=n; ++i) {
		int c=(s[i]=='R');
		head[i]=i;
		if(!end[!c].empty()) {
			cat(end[!c].back(), i);
			end[!c].pop_back();
		}
		end[c].push_back(i);
	}
	std::cout<<end[0].size()+end[1].size()-1<<"\n";
	for(int i=0; i<2; ++i)
		for(int j: end[i]) qaq[s[head[j]]=='R'][i].push_back(j);
	while(!qaq[0][0].empty()&&!qaq[1][1].empty()) {
		int u=qaq[0][0].back(), v=qaq[1][1].back();
		qaq[0][0].pop_back();
		qaq[1][1].pop_back();
		cat(u, v);
		qaq[0][1].push_back(v);
	}
	for(int t=0; t<2; ++t)
		while(qaq[t][!t].size()>1) {
			int u=qaq[t][!t].back();
			qaq[t][!t].pop_back();
			cat(u, qaq[t][!t].back());
		}
	if(qaq[0][0].empty()&&qaq[1][1].empty()) {
		if(!qaq[0][1].empty()&&!qaq[1][0].empty()) {
			int u=qaq[0][1][0], v=qaq[1][0][0], w;
			if(u>v) std::swap(u, v);
			next[prev[v]]=head[u];
			prev[head[u]]=prev[v];
			prev[v]=u;
			next[u]=v;
			last=v;
		} else {
			int t=qaq[0][1].empty();
			last=qaq[t][!t][0];
		}
	} else {
		int t=qaq[0][0].empty();
		last=qaq[t][t][0];
		if(!qaq[!t][t].empty()) {
			int u=qaq[!t][t][0];
			cat(last, u);
			last=u;
		}
		if(!qaq[t][!t].empty()) cat(qaq[t][!t][0], last);
	}
	for(int i=head[last]; i; i=next[i]) printf("%d ", i);
	puts("");
	return 0;
}