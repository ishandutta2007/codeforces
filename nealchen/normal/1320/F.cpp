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
//const u32 P=;
//inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//inline u32 sum(u32 a, u32 b) {return (a+=b)<P?a:a-P;}
//inline u32 dif(u32 a, u32 b) {return (a-=b)&0x80000000?a+P:a;}
//u64 power(u64 a, int b) {
//	u64 ans=1;
//	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
//	return ans;
//}

const int N=2e5, D[][3]={
	1, 0, 0,
	-1, 0, 0,
	0, 1, 0,
	0, -1, 0,
	0, 0, 1,
	0, 0, -1,
};
int n, m, k, sz[3], col[6][N];
bool vis[N][6], gg[N];
std::set<int> c[N];
std::queue<int> q;

int id(int x, int y, int z) {
	return (x*m+y)*k+z;
}

void real(int b, int *res) {
	res[0]=b/k/m;
	res[1]=b/k%m;
	res[2]=b%k;
}

void rm(int id) {
	if(gg[id]) return;
	gg[id]=true;
	q.push(id);
}

int observer(int d, int *co) {
	int res=0;
	for(int i=0; i<3; ++i) {
		if(!D[d][i]) res=res*sz[i]+co[i];
	}
	return res;
}

void cast(int d, int x, int y, int z) {
	int co[]={x, y, z}, b=id(x, y, z), o=observer(d, co);
	vis[b][d]=true;
	if(col[d][o]==0) return rm(b);
	c[b].insert(col[d][o]);
	if(c[b].size()>1) rm(b);
}

int main() {
	n=sz[0]=rd();
	m=sz[1]=rd();
	k=sz[2]=rd();
	for(int i=0; i<m*k; ++i) col[0][i]=rd(), cast(0, 0, i/k, i%k);
	for(int i=0; i<m*k; ++i) col[1][i]=rd(), cast(1, n-1, i/k, i%k);
	for(int i=0; i<n*k; ++i) col[2][i]=rd(), cast(2, i/k, 0, i%k);
	for(int i=0; i<n*k; ++i) col[3][i]=rd(), cast(3, i/k, m-1, i%k);
	for(int i=0; i<n*m; ++i) col[4][i]=rd(), cast(4, i/m, i%m, 0);
	for(int i=0; i<n*m; ++i) col[5][i]=rd(), cast(5, i/m, i%m, k-1);
	while(!q.empty()) {
		int b=q.front();
		q.pop();
		for(int i=0; i<6; ++i) {
			if(vis[b][i]) {
				int co[3];
				bool in=true;
				real(b, co);
				while(in && gg[id(co[0], co[1], co[2])]) {
					for(int j=0; j<3; ++j) {
						co[j]+=D[i][j];
						in &= co[j]>=0&&co[j]<sz[j];
					}
				}
				if(in)
					cast(i, co[0], co[1], co[2]);
				else {
					real(b, co);
					if(col[i][observer(i, co)]) {
						puts("-1");
						return 0;
					}
				}
			}
		}
	}
	for(int i=0, b=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			for(int l=0; l<k; ++l) {
				printf("%d ", gg[b]||c[b].empty()?0:*c[b].begin());
				++b;
			}
			puts("");
		}
		puts("");
	}
	return 0;
}