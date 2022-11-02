#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;

const int N=1e5+5;
int n, last[26], l[N], r[N], pre[N][27], nex[N][27], f[N][27], g[N][27], curl[N], curr[N], flift[17][N], glift[17][N];
char s[N];
long long fsum[17][N], gsum[17][N];
int main() {
	assert(scanf("%s", s)==1);
	n=strlen(s);
	for(int i=0; i<n; ++i) s[i]-='a';
	for(int i=0; i<n; ++i) {
		l[i]=last[s[i]];
		last[s[i]]=i;
		memcpy(pre[i], last, sizeof(last));
		std::sort(pre[i], pre[i]+26, std::greater<int>());
		pre[i][26]=-1;
	}
	for(int i=0; i<26; ++i) last[i]=n-1;
	for(int i=n; i--; ) {
		r[i]=last[s[i]];
		last[s[i]]=i;
		memcpy(nex[i], last, sizeof(last));
		std::sort(nex[i], nex[i]+26);
		nex[i][26]=n;
	}
	for(int i=0; i<n; ++i) {
		curl[i]=curr[i]=i;
		f[i][0]=g[i][0]=i;
		for(int j=0; j<26; ++j) {
			f[i][j+1]=std::min(f[i][j], l[nex[i][j]]);
			g[i][j+1]=std::max(g[i][j], r[pre[i][j]]);
		}
	}
	long long ans=0;
	for(int t=1; t<=26; ++t) {
		for(int i=0; i<n; ++i) {
			flift[0][i]=f[i][t];
			glift[0][i]=g[i][t];
			fsum[0][i]=gsum[0][i]=i;
		}
		for(int i=1; (1<<i)<=n; ++i)
			for(int j=0; j<n; ++j) {
				flift[i][j]=flift[i-1][flift[i-1][j]];
				glift[i][j]=glift[i-1][glift[i-1][j]];
				fsum[i][j]=fsum[i-1][j]+fsum[i-1][flift[i-1][j]];
				gsum[i][j]=gsum[i-1][j]+gsum[i-1][glift[i-1][j]];
			}
		for(int i=0; i<n; ++i) {
			for(int j=31-__builtin_clz(n); j>=0; --j) {
				int nexl=flift[j][curl[i]], nexr=glift[j][curr[i]];
				if(nexr<nex[nexl][t]) {
					ans+=((n-1ll)<<j)+fsum[j][curl[i]]-gsum[j][curr[i]];
					curl[i]=nexl, curr[i]=nexr;
				}
			}
			if(curr[i]<nex[curl[i]][t]) {
				ans+=n-1+curl[i]-curr[i];
				curl[i]=f[curl[i]][t];
				curr[i]=g[curr[i]][t];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}