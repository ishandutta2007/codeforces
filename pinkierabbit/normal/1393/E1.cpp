#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define MM 20005
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

struct SuffixArray {
	int N, Str[MM], SA[MM], rk[MM], SA2[MM];
	int Sig, Buk[MM], Tmp[MM];
	int Height[MM];
	
	inline void RSort() {
		for (int i = 1; i <= Sig; ++i) Buk[i] = 0;
		for (int i = 1; i <= N; ++i) ++Buk[rk[i]];
		for (int i = 1; i <= Sig; ++i) Buk[i] += Buk[i - 1];
		for (int i = N; i >= 1; --i) SA[Buk[rk[SA2[i]]]--] = SA2[i];
	}
	inline void BuildSA() {
		/* Init Str */
		for (int i = 1; i <= N; ++i) rk[i] = Str[i], SA2[i] = i;
		rk[N + 1] = 0;
		Sig = 27 /* maximum letter in Str */, RSort();
		for (int j = 1; j < N; j <<= 1) {
			int P = 0;
			for (int i = 1; i <= j; ++i) SA2[++P] = N - j + i;
			for (int i = 1; i <= N; ++i) if (SA[i] > j) SA2[++P] = SA[i] - j;
			RSort();
			Tmp[SA[1]] = P = 1;
			for (int i = 2; i <= N; ++i) {
				if (rk[SA[i]] != rk[SA[i - 1]] || rk[SA[i] + j] != rk[SA[i - 1] + j]) ++P;
				Tmp[SA[i]] = P;
			}
			for (int i = 1; i <= N; ++i) rk[i] = Tmp[i];
			Sig = P;
			if (Sig == N) break;
		}
	}
	inline void GetHeight() {
		int k = 0;
		for (int i = 1; i <= N; ++i) {
			if (rk[i] == 1) k = Height[1] = 0;
			else {
				if (k) --k;
				int j = SA[rk[i] - 1];
				while (i + k <= N && j + k <= N && Str[i + k] == Str[j + k]) ++k;
				Height[rk[i]] = k;
			}
		}
	}
	
	int BLCP[MM][21], Bt;
	inline void InitST() {
		for (int i = 1; i <= N; ++i) BLCP[i][0] = Height[i];
		while (2 << Bt <= N) ++Bt;
		for (int j = 1; j <= Bt; ++j)
			for (int i = 1 << j; i <= N; ++i)
				BLCP[i][j] = std::min(BLCP[i][j - 1], BLCP[i - (1 << (j - 1))][j - 1]);
	}
	inline int LCP(int x, int y) {
		if (x == y) return N + 1;
		x = rk[x], y = rk[y];
		if (x > y) std::swap(x, y);
		int j = 31 - __builtin_clz(y - x);
		return std::min(BLCP[y][j], BLCP[x + (1 << j)][j]);
	}
	inline void GetRange(int pos, int k, int &lb, int &rb) {
		int lj = 0;
		while (pos > 1 << lj && BLCP[pos][lj] >= k) ++lj;
		for (--lj, lb = pos; lj >= 0; --lj)
			if (lb > 1 << lj && BLCP[lb][lj] >= k)
				lb -= 1 << lj;
		int rj = 0;
		while (N - pos >= 1 << rj && BLCP[pos + (1 << rj)][rj] >= k) ++rj;
		for (--rj, rb = pos; rj >= 0; --rj)
			if (N - rb >= 1 << rj && BLCP[rb + (1 << rj)][rj] >= k)
				rb += 1 << rj;
	}
} C;

int n,len[MN];
char str[MM];
vector<int>s[MN],f[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n){
		scanf("%s",str);
		len[i]=strlen(str);
		s[i].resize(len[i]+2);
		f[i].resize(len[i]+1);
		F(j,1,len[i])s[i][j]=str[j-1]-'a'+1;
		s[i][len[i]+1]=0;
	}
//	F(i,1,n){
//		F(j,1,len[i])printf("%c",s[i][j]-1+'a');
//		puts("");
//	}
	F(k,0,len[1])f[1][k]=1;
	F(i,2,n){
		int len1=len[i-1],len2=len[i];
		C.N=len1+len2+1;
		F(j,1,len1)C.Str[j]=s[i-1][j];
		F(j,1,len2)C.Str[len1+1+j]=s[i][j];
		C.Str[len1+1]=27;
		C.BuildSA(),C.GetHeight(),C.InitST();
		F(k,0,len2){
			f[i][k]=0;
			F(j,0,len1){
				int ok=1;
				if(k&&j){
					int x=C.LCP(1,len1+2);
					if(x<min(j,k)-1){
						if(s[i-1][x+1]>s[i][x+1])ok=0;
					}else{
						if(j<k){
							x=C.LCP(j+1,len1+j+1);
							if(x<k-j){
								if(s[i-1][j+x+1]>s[i][j+x])ok=0;
							}else{
								x=C.LCP(k+1,len1+k+2);
								if(s[i-1][k+x+1]>s[i][k+x+1])ok=0;
							}
						}else if(j>k){
							x=C.LCP(k,len1+k+2);
							if(x<j-k){
								if(s[i-1][k+x]>s[i][k+x+1])ok=0;
							}else{
								x=C.LCP(j+1,len1+j+2);
								if(s[i-1][j+x+1]>s[i][j+x+1])ok=0;
							}
						}else{
							x=C.LCP(j+1,len1+k+2);
							if(s[i-1][j+x+1]>s[i][k+x+1])ok=0;
						}
					}
				}else if(!k&&!j){
					int x=C.LCP(1,len1+2);
					if(s[i-1][x+1]>s[i][x+1])ok=0;
				}else if(!j){
					int x=C.LCP(1,len1+2);
					if(x<k-1){
						if(s[i-1][x+1]>s[i][x+1])ok=0;
					}else{
						x=C.LCP(k,len1+k+2);
						if(s[i-1][k+x]>s[i][k+x+1])ok=0;
					}
				}else{
					int x=C.LCP(1,len1+2);
					if(x<j-1){
						if(s[i-1][x+1]>s[i][x+1])ok=0;
					}else{
						x=C.LCP(j+1,len1+j+1);
						if(s[i-1][j+x+1]>s[i][j+x])ok=0;
					}
				}
				if(ok)f[i][k]=(f[i][k]+f[i-1][j])%mod;
			}
		}
	}
	int ans=0;
	F(j,0,len[n])ans=(ans+f[n][j])%mod;
	printf("%d\n",ans);
	return 0;
}