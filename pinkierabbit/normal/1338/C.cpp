#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
ll n;
void Print(){
	static int vis[100005];
	for(int i=1;i<=50;++i){
		for(int a=1;a<512;++a)if(!vis[a])
			for(int b=1;b<512;++b)if(b!=a&&!vis[b]&&!vis[a^b]){
					printf("%d %d %d\n",a,b,a^b);
					vis[a]=vis[b]=vis[a^b]=1;
					goto rua;
				}
		rua:;
	}
}
const int vvv[4][4]={
	{0,0,0,0},
	{0,1,2,3},
	{0,2,3,1},
	{0,3,1,2}
};
int main(){
//	Print();
	int tests=0;
	scanf("%d",&tests);
	while(tests--){
		scanf("%lld",&n);
		ll g=(n-1)/3+1,r=(n-1)%3+1;
//		printf("g,r = %lld,%lld\n",g,r);
		int j=-1;ll s=0;
		while(s<g)++j,s+=1ll<<(2*j);
		s-=1ll<<(2*j);
		ll x=g-s-1;
//		printf("j,x = %d,%lld\n",j,x);
		ll ans=r;
		for(int i=j-1;i>=0;--i){
			ans=ans<<2|vvv[r][x>>(2*i)&3];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
// 1, 4, 16, 64
// [1 2 3]                                      : 2
// 01
// 10
// 11
// [4 8 12] [5 10 15] [6 11 13] [7 9 14]        : 4
// 01(00/01/10/11)
// 10(00/10/11/01)
// 11(00/11/01/10)
// [16 32 48] [17 34 51] [18 35 49] [19 33 50]  : 6
// [20 40 60] [21 42 63] [22 43 61] [23 41 62]  : 6
// [24 44 52] [25 46 55] [26 47 53] [27 45 54]  : 6
// [28 36 56] [29 38 59] [30 38 57] [31 37 58]  : 6
// 01(00/01/10/11)(00/01/10/11)
// 10(00/10/11/01)(00/10/11/01)
// 11(00/11/01/10)(00/11/01/10)

// 01(00/01/10/11)(00/01/10/11)(00/01/10/11)
// 10(00/10/11/01)(00/10/11/01)(00/10/11/01)
// 11(00/11/01/10)(00/11/01/10)(00/11/01/10)

// (00/01/10/11)(00/01/10/11)(00/01/10/11)(00/01/10/11)(00/01/10/11)(00/01/10/11)(00/01/10/11)
// (00/10/11/01)(00/10/11/01)(00/10/11/01)(00/10/11/01)(00/10/11/01)(00/10/11/01)(00/10/11/01)
// (00/11/01/10)(00/11/01/10)(00/11/01/10)(00/11/01/10)(00/11/01/10)(00/11/01/10)(00/11/01/10)