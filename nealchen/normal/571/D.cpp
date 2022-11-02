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
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

const int N=5e5+1;
int op[N], arg1[N], arg2[N], where[N], cur[N], tag[N], mergetime[N];
s64 cnt[N], add[N], before[N];
std::vector<int> set[N], raided[N];
int main() {
	int n=rd(), m=rd();
	for(int i=1; i<=m; ++i) {
		char c;
		while((unsigned)(c=getchar())-65u>26u);
		if(c=='U') op[i]=0;
		if(c=='M') op[i]=1;
		if(c=='A') op[i]=2;
		if(c=='Z') op[i]=3;
		if(c=='Q') op[i]=4;
		arg1[i]=rd();
		if(op[i]<2) arg2[i]=rd();
	}
	for(int i=1; i<=n; ++i) set[i]={i}, where[i]=i;
	for(int i=1; i<=m; ++i) {
		auto get=[](int d) {
			int t=tag[where[d]];
			return mergetime[d]<t?t:cur[d];
		};
		if(op[i]==1) {
			int u=where[arg1[i]], v=where[arg2[i]];
			if(set[u].size()<set[v].size()) std::swap(u, v);
			for(int j: set[v]) {
				cur[j]=get(j);
				set[where[j]=u].push_back(j);
				mergetime[j]=i;
			}
			set[v].clear();
		}
		if(op[i]==3) tag[where[arg1[i]]]=i;
		if(op[i]==4) raided[get(arg1[i])].push_back(i);
	}
	for(int i=1; i<=n; ++i) set[i]={i}, where[i]=i;
	for(int i=1; i<=m; ++i) {
		auto get=[](int d) {
			return cnt[d]+add[where[d]];
		};
		if(op[i]==0) {
			int u=where[arg1[i]], v=where[arg2[i]];
			if(set[u].size()<set[v].size()) std::swap(u, v);
			for(int j: set[v]) {
				cnt[j]+=add[v]-add[u];
				set[where[j]=u].push_back(j);
			}
			set[v].clear();
		}
		if(op[i]==2) add[where[arg1[i]]]+=set[where[arg1[i]]].size();
		if(op[i]==3) for(int j: raided[i]) before[j]=get(arg1[j]);
		if(op[i]==4) printf("%lld\n", get(arg1[i])-before[i]);
	}
	return 0;
}