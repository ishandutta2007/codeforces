#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
void pre(int x) {
	if(x==3) puts("1");
	if(x==7) puts("1");
	if(x==15) puts("5");
	if(x==31) puts("1");
	if(x==63) puts("21");
	if(x==127) puts("1");
	if(x==255) puts("85");
	if(x==511) puts("73");
	if(x==1023) puts("341");
	if(x==2047) puts("89");
	if(x==4095) puts("1365");
	if(x==8191) puts("1");
	if(x==16383) puts("5461");
	if(x==32767) puts("4681");
	if(x==65535) puts("21845");
	if(x==131071) puts("1");
	if(x==262143) puts("87381");
    if(x == 33554431) puts("1082401");
	if(x==524287) puts("1");
	if(x==1048575) puts("349525");
	if(x==2097151) puts("299593");
	if(x==4194303) puts("1398101");
	if(x==8388607) puts("178481");
	if(x==16777215) puts("5592405");	
}

inline void Solve(){
    int x;scanf("%I64d",&x);
	int cnt=0,tp=0;
	FOR(i,0,30){
		if(x&(1ll<<i)) tp=i,++cnt;
	}
	if(cnt==tp+1) pre(x);
	else printf("%I64d\n",(1ll<<(tp+1))-1ll);
}

signed main() {
	int n;scanf("%I64d",&n);
	while(n--) Solve();
	return 0;
}