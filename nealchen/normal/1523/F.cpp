#include <bits/stdc++.h>
int ans;
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
//inline int sum(int a, int b) {return (a+=b)<P?a:a-P;}
//inline int dif(int a, int b) {return (a-=b)<0?a+P:a;}
//u64 power(u64 a, int b) {
//	u64 ans=1;
//	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
//	return ans;
//}

struct P{int x, y, t;};
P rdpos(){return {rd(), rd()};}
int dis(P a, P b){return abs(a.x-b.x)+abs(a.y-b.y);}
bool operator<(P a, P b) {return a.t<b.t;}

int n, m, f[1<<14][101], g[1<<14][100], mindis[1<<14][114];
P a[114], *b;

int main() {
	n=rd(), m=rd();
	for(int i=0;i<n;++i)a[i]=rdpos();
	b=a+n;
	for(int i=0;i<m;++i)b[i]=rdpos(),b[i].t=rd();
	std::sort(b,b+m);
	for(int s=0;s<(1<<n);++s)memset(mindis[s],63,(n+m)*sizeof(int));
	for(int s=1;s<(1<<n);++s){
		int u=__builtin_ctz(s), t=s&(s-1);
		for(int i=0;i<n+m;++i)mindis[s][i]=std::min(mindis[t][i],dis(a[u],a[i]));
	}
	for(int s=0;s<(1<<n);++s) {
		memset(f[s],63,(m+1)*sizeof(int));
		memset(g[s],192,m*sizeof(int));
	}
	for(int i=0;i<n;++i) f[1<<i][0]=0;
	for(int i=0;i<m;++i) g[0][i]=1;
	for(int s=0;s<(1<<n);++s){
		for(int i=0;i<=m;++i){
			if(f[s][i]<0)continue;
			for(int q=0;q<n;++q){
				if(~s>>q&1)cmin(f[s|1<<q][i], mindis[s][q]+f[s][i]);
			}
			for(int j=0;j<m;++j){
				if(f[s][i]+mindis[s][j+n]<=b[j].t) cmax(g[s][j],i+1);
			}
		}
		for(int i=0;i<m;++i){
			if(g[s][i]<0)continue;
			for(int q=0;q<n;++q)if(~s>>q&1){
				cmin(f[s|1<<q][g[s][i]], std::min(dis(a[q], b[i]), mindis[s][q])+b[i].t);
			}
			for(int j=i+1;j<m;++j){
				if(std::min(dis(b[i],b[j]),mindis[s][j+n])<=b[j].t-b[i].t) cmax(g[s][j],g[s][i]+1);
			}
			cmax(ans,g[s][i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}