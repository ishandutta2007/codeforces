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

struct E {
	int u, v;
	long long d;
};
const int N=1e5+1, M=3e5;
int n, m, u[M], v[M], d[M];
long long tot[N];
std::pair<long long, int> p[N];
std::vector<E> ans;
int main() {
	n=rd(), m=rd();
	for(int i=0; i<m; ++i) {
		u[i]=rd(), v[i]=rd(), d[i]=rd();
		tot[u[i]]+=d[i];
		tot[v[i]]-=d[i];
	}
	for(int i=1; i<=n; ++i) p[i]={tot[i], i};
	std::sort(p+1, p+n+1);
	for(int l=1, r=n; l<r; ) {
		if(p[l].first+p[r].first>0) {
			if(p[l].first) ans.push_back({p[r].second, p[l].second, -p[l].first});
			p[r].first+=p[l].first;
			++l;
		} else {
			if(p[r].first) ans.push_back({p[r].second, p[l].second, p[r].first});
			p[l].first+=p[r].first;
			if(p[l].first==0) ++l;
			--r;
		}
	}
	std::cout<<ans.size()<<"\n";
	for(auto e: ans) std::cout<<e.u<<" "<<e.v<<" "<<e.d<<"\n";
	return 0;
}