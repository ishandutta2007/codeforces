#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
typedef long long ll;
typedef std::pair<int,int> pii;
#define lson rt<<1
#define rson rt<<1|1
#define clr(a,x) memset(a,x,sizeof(a))
#define FOR(i,a,b) for(int i=(a);i<=(int)(b);++i)
#define REP(i,a,b) for(int i=(a);i>=(int)(b);--i)
#define EFOR(i,u) for(int i=lnk[u];i;i=nxt[i])
#define DEBUG(x) std::cerr<<#x<<" = "<<x<<'\n'
const int inf=1<<30;
const long long INF=1LL<<61;
void judge() {
#ifdef SIYUAN
	freopen("in.txt","r",stdin);
#endif
}
inline char nc() {
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
template <class Tp> inline void read(register Tp &s) {
	s=0;bool neg=0;char c=nc();for(;c<'0'||c>'9';neg|=(c=='-'),c=nc());
	for(;c>='0'&&c<='9';s=10*s+(c^48),c=nc());neg&&(s=-s);
}


int main() {
//	judge();
	int T,a[10];
	for(scanf("%d",&T);T--;) {
		int n,cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=7;++i) scanf("%d",&a[i]),cnt+=a[i];
		int ans=1<<30;
		for(int i=1;i<=7;++i) {
			int sum=0;
			bool flg=1;
			for(int j=i;j<=7;++j) {
				sum+=a[j];
				if(sum==n) {
					ans=std::min(ans,j-i+1);
					flg=0;
					break;
				}
			}
			if(!flg) continue;
			int ret=7-i+1;
			ret+=(n-sum-1)/cnt*7;
			int r=(n-sum-1)%cnt+1;
			sum=0;
			for(int j=1;j<=7;++j) {
				sum+=a[j];
				if(sum==r) {
					ret+=j;
					break;
				}
			}
			ans=std::min(ans,ret);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
2
0 1 0 0 0 0 0
*/