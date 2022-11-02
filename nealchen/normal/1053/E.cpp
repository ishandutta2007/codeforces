#include <set>
#include <deque>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
typedef std::pair<int, int> Pair;
const int N=5e5+5;
int n, a[2*N], ans[2*N], cnt;
bool vis[N];
std::vector<int> unused;
std::deque<Pair> cur;
std::vector<Pair> geteq;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
void gg() {
	puts("no");
	exit(0);
}
void check() {
	static std::vector<int> pos[N];
	std::set<int> s;
	std::vector<Pair> order;
	if(a[1]!=0&&a[2*n-1]!=0&&a[1]!=a[2*n-1]) gg();
	for(int i=1; i<2*n; ++i) if(a[i]!=0) {
		if(pos[a[i]].empty()) order.emplace_back(i, a[i]);
		pos[a[i]].push_back(i);
	}
	for(int i=1; i<=n; ++i) if(!pos[i].empty())
		for(int j: pos[i]) if(j%2!=pos[i][0]%2) gg();
	std::sort(order.begin(), order.end());
	for(auto v: order) {
		auto it=s.lower_bound(v.first);
		auto P=pos[v.second];
		if(it!=s.end()&&*it<P.back()) gg();
		s.insert(P.begin(), P.end());
	}
}
void go() {
	std::deque<std::pair<int, int>> help;
	while(help.size()+cur.size()>=3) {
		if(help.size()<3) {
			help.push_back(cur.front());
			cur.pop_front();
			continue;
		}
		auto v1=help.back(); help.pop_back();
		auto v2=help.back(); help.pop_back();
		auto v3=help.back(); help.pop_back();
		if(v1.first==0&&v2.first!=0&&v3.first!=0) {
			ans[v1.second]=v3.first;
			help.push_back(v3);
		} else {
			help.push_back(v3);
			help.push_back(v2);
			help.push_back(v1);
		}
		if(cur.empty()) break;
		help.push_back(cur.front());
		cur.pop_front();
	}
	while(!help.empty()) {
		cur.push_back(help.front());
		help.pop_front();
	}
}
void solve(int root) {
	int need=(cur.size()+1)/2-cnt;
	std::deque<std::pair<int, int>> help;
	if(need<0) gg();
	while(!cur.empty()) {
		auto v=cur.front();
		cur.pop_front();
		if(need>0&&v.first==0) {
			--need;
			if(unused.empty()) gg();
			v.first=unused.back();
			unused.pop_back();
			ans[v.second]=v.first;
		}
		help.push_back(v);
	}
	while(!help.empty()) {
		cur.push_front(help.front());
		help.pop_front();
	}
	go();
	if(root==-1&&cur.back().first==0) {
		root=cur.front().first;
		ans[cur.back().second]=root;
		cur.pop_front();
		cur.pop_back();
		solve(root);
		return;
	}
	std::reverse(cur.begin(), cur.end());
	go();
	while(!cur.empty()) {
		auto v=cur.front();
		cur.pop_front();
		if(v.first==0) ans[v.second]=root;
	}
}
int main() {
	int (*rd)()=read<int>;
	n=rd();
	for(int i=1; i<2*n; ++i) {
		a[i]=rd();
		if(a[i]!=0) vis[a[i]]=true;
	}
	check();
	for(int i=1; i<=n; ++i) {
		if(!vis[i]) unused.push_back(i);
		vis[i]=false;
	}
	a[1]=a[2*n-1]=a[1]|a[2*n-1];
	for(int i=1; i<2*n; ++i) ans[i]=a[i];
	for(int i=1; i<2*n; ++i) {
		if(a[i]==0) {
			geteq.emplace_back(0, i);
		} else if(vis[a[i]]) {
			cnt=0;
			while(geteq.back().first!=a[i]) {
				if(geteq.back().first>0) {
					++cnt;
					vis[geteq.back().first]=false;
				}
				cur.push_front(geteq.back());
				geteq.pop_back();
			}
			solve(a[i]);
		} else {
			geteq.emplace_back(a[i], i);
			vis[a[i]]=true;
		}
	}
	cnt=0;
	while(!geteq.empty()) {
		if(geteq.back().first>0) {
			++cnt;
			vis[geteq.back().first]=false;
		}
		cur.push_front(geteq.back());
		geteq.pop_back();
	}
	solve(-1);
	puts("yes");
	for(int i=1; i<2*n; ++i) printf("%d ", ans[i]);
	puts("");
	return 0;
}