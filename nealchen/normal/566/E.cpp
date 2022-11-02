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

typedef unsigned long long u64, Set[16];
bool test(const Set s, int x) {return s[x/64]>>(x%64)&1;}
void set(Set s, int x) {s[x/64]|=1llu<<(x%64);}
bool eq(Set s, Set t) {return memcmp(s, t, sizeof(Set))==0;}

const int N=1000;
int n, size[N], deg[N];
Set list[N], adj[N], in;
std::vector<std::pair<int, int>> edge;
int main() {
	n=rd();
	for(int i=0; i<n; ++i) {
		size[i]=rd();
		for(int j=0; j<size[i]; ++j) set(list[i], rd()-1);
	}
	if(std::count(size, size+n, n)==n) {
		for(int i=2; i<=n; ++i) printf("1 %d\n", i);
		return 0;
	}
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j) {
			int cnt=0;
			for(int k=0; k<16; ++k) cnt+=__builtin_popcountll(list[i][k]&list[j][k]);
			if(cnt==2) {
				int u=-1, v=-1;
				for(int k=0; k<16; ++k)
					for(u64 t=list[i][k]&list[j][k]; t; t&=t-1)
						(~u?v:u)=k*64+__builtin_ctzll(t);
				if(!test(adj[u], v)) {
					printf("%d %d\n", u+1, v+1);
					edge.emplace_back(u, v);
					++deg[u], set(adj[u], v);
					++deg[v], set(adj[v], u);
				}
			}
		}
	if(edge.size()==1) {
		int k=std::find_if(size, size+n, [](int x) {return x!=n;})-size, u, v;
		std::tie(u, v)=edge[0];
		for(int i=0; i<n; ++i) if(deg[i]==0) printf("%d %d\n", (test(list[k], i)?u:v)+1, i+1);
		return 0;
	}
	for(int i=0; i<n; ++i) if(deg[i]) set(in, i), set(adj[i], i);
	for(int i=0; i<n; ++i)
		if(deg[i]==0) {
			int minsize=n, id;
			Set s;
			for(int j=0; j<n; ++j) if(test(list[j], i)&&cmin(minsize, size[j])) id=j;
			for(int j=0; j<16; ++j) s[j]=in[j]&list[id][j];
			for(int j=0; j<n; ++j)
				if(eq(s, adj[j])) {
					printf("%d %d\n", i+1, j+1);
					break;
				}
		}
	return 0;
}