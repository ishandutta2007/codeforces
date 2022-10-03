#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MS 6000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n;
int c[2][MS],s[MS],cnt;
void ins(int x){
	int now=1;
	dF(j,29,0){
		++s[now];
		int y=x>>j&1;
		if(!c[y][now])c[y][now]=++cnt;
		now=c[y][now];
	}
}
int dp(int u){
	if(!s[u])return 0;
	int r=inf;
	if(c[0][u])r=min(r,dp(c[0][u])+max(s[c[1][u]]-1,0));
	if(c[1][u])r=min(r,dp(c[1][u])+max(s[c[0][u]]-1,0));
	return r;
}
int main(){int x;
	scanf("%d",&n),cnt=1;
	F(i,1,n)scanf("%d",&x),ins(x);
	printf("%d\n",dp(1));
	return 0;
}