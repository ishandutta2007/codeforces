#include <set>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=1e5+1;
struct Flight {int d, f, t, c;};
int cost[N];
std::multiset<int> heap[N];
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
int main() {
	int (*rd)()=read<int>, n, m, k;
	long long ans=1e18, cur=0;
	std::vector<Flight> arr, dep;
	n=rd(), m=rd(), k=rd();
	for(int i=0; i<m; ++i) {
		Flight cur={rd(), rd(), rd(), rd()};
		(cur.t==0?arr:dep).push_back(cur);
	}
	std::sort(arr.begin(), arr.end(), [](const Flight &x, const Flight &y) {return x.d<y.d;});
	std::sort(dep.begin(), dep.end(), [](const Flight &x, const Flight &y) {return x.d<y.d;});
	for(int i=1; i<=n; ++i) cost[i]=1e9;
	for(Flight i: dep) heap[i.t].insert(i.c);
	for(int i=1; i<=n; ++i) {
		if(heap[i].empty()) {
			puts("-1");
			return 0;
		}
		cur+=*heap[i].begin();
	}
	for(int d=1, i=0, j=0, cnt=n; ; ++d) {
		for(; i<arr.size()&&arr[i].d<=d; ++i) {
			int id=arr[i].f;
			if(cost[id]==1e9) --cnt; else cur-=cost[id];
			cmin(cost[id], arr[i].c);
			cur+=cost[id];
		}
		for(; j<dep.size()&&dep[j].d<=d+k; ++j) {
			int id=dep[j].t;
			cur-=*heap[id].begin();
			heap[id].erase(heap[id].find(dep[j].c));
			if(heap[id].empty()) {
				std::cout<<(ans>1e17?-1:ans)<<std::endl;
				return 0;
			}
			cur+=*heap[id].begin();
		}
		if(cnt==0) cmin(ans, cur);
	}
	return 0;
}