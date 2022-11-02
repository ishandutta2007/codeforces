#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
const int N=2e5+1;
bool vis[N];
int n, w[N], to[2*N], l[N], head[N], next[2*N], size[N], cho;
double f[N], ans, lagoon;
std::vector<int> sub;
void measure(int u) {
	vis[u]=true;
	sub.push_back(u);
	size[u]=1;
	for(int i=head[u]; i; i=next[i])
		if(!vis[to[i]]) {
			measure(to[i]);
			size[u]+=size[to[i]];
		}
	vis[u]=false;
}
void sol(int u, int p, double pinkrabbit) {
	f[u]=sqrt(pinkrabbit)*w[u];
	lagoon+=pinkrabbit*f[u];
	for(int i=head[u]; i; i=next[i])
		if(to[i]!=p) {
			sol(to[i], u, pinkrabbit+l[i>>1]);
			f[u]+=f[to[i]];
		}
}
void bin(int in) {
	int g;
	sub.clear();
	measure(in);
	for(int i=0; i<sub.size(); ++i) {
		g=sub[i];
		bool ok=size[g]*2>=size[in];
		for(int j=head[g]; j&&ok; j=next[j]) ok&=vis[to[j]]||size[to[j]]>=size[g]||size[to[j]]*2<=size[in];
		if(ok) break;
	}
	lagoon=0;
	sol(g, 0, 0);
	if(cmin(ans, lagoon)) cho=g;
	vis[g]=true;
	for(int i=head[g]; i; i=next[i])
		if(2*f[to[i]]>f[g]) {
			if(!vis[to[i]]) bin(to[i]);
			return;
		}
}
int main() {
	n=rd();
	for(int i=1; i<=n; ++i) w[i]=rd();
	for(int i=1, j=2; i<n; ++i) {
		int u=rd(), v=rd();
		l[i]=rd();
		to[j]=v, next[j]=head[u], head[u]=j++;
		to[j]=u, next[j]=head[v], head[v]=j++;
	}
	ans=1e100;
	bin(1);
	printf("%d %.15lf\n", cho, ans);
	return 0;
}