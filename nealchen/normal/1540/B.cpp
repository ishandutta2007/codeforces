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
const int P=1e9+7;
inline int &inc(int &a, int b) {return (a+=b)<P?a:(a-=P);}
inline int &dec(int &a, int b) {return (a-=b)<0?(a+=P):a;}
inline int sum(int a, int b) {return (a+=b)<P?a:a-P;}
inline int dif(int a, int b) {return (a-=b)<0?a+P:a;}
u64 power(u64 a, int b) {
	u64 ans=1;
	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
	return ans;
}

const int N=205;
int n, f[N][N], dis[N], ans;
std::vector<int> out[N];
std::vector<int> dfs(int u, int d) {
	std::vector<int> res{u};
	dis[u]=d;
	for(int v: out[u]) {
		if(dis[v]==-1) {
			auto sub=dfs(v, d+1);
			for(int x: res) {
				for(int y: sub) {
					int a=dis[x]-d, b=dis[y]-d;
					if(x>y) std::swap(a, b);
					inc(ans, f[a][b]);
				}
			}
			res.insert(res.end(), sub.begin(), sub.end());
		}
	}
	return res;
}
int main() {
	n=rd();
	for(int i=1; i<n; ++i) {
		int u=rd(), v=rd();
		out[u].push_back(v);
		out[v].push_back(u);
	}
	for(int i=1; i<=n; ++i)
		f[i][0]=1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			f[i][j]=sum(f[i-1][j], f[i][j-1]);
			if(f[i][j]%2!=0) f[i][j]+=P;
			f[i][j]/=2;
		}
	}
	for(int i=1; i<=n; ++i) {
		memset(dis+1, -1, n*sizeof(int));
		dfs(i, 0);
	}
	ans=ans*power(n, P-2)%P;
	printf("%d\n", ans);
	return 0;
}