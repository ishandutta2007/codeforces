#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
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
int (*rd)()=read<int>;
//const int P=;
//inline int &inc(int &a, int b) {return (a+=b)<P?a:(a-=P);}
//inline int &dec(int &a, int b) {return (a-=b)<0?(a+=P):a;}
//inline int add(int a, int b) {return (a+=b)<P?a:a-P;}
//inline int sub(int a, int b) {return (a-=b)<0?a+P:a;}
//u64 power(u64 a, int b) {
//	u64 ans=1;
//	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
//	return ans;
//}

const int N=2e5+5;
std::set<int> adj[N];
int query(int x) {
	return adj[x].empty() || x>*adj[x].rbegin();
}
int main() {
	int n=rd(), m=rd();
	while(m--) {
		int u=rd(), v=rd();
		adj[u].insert(v);
		adj[v].insert(u);
	}
	int ans=0;
	for(int i=1; i<=n; ++i) ans+=query(i);
	int q=rd();
	while(q--) {
		int op=rd(), u, v;
		if(op==1) {
			u=rd(), v=rd();
			ans-=query(u)+query(v);
			adj[u].insert(v);
			adj[v].insert(u);
			ans+=query(u)+query(v);
		} else if(op==2) {
			u=rd(), v=rd();
			ans-=query(u)+query(v);
			adj[u].erase(v);
			adj[v].erase(u);
			ans+=query(u)+query(v);
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}