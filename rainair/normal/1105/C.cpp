
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
#define se second
#define U unsigned
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
const int N=2e5+5;
const int mod=1e9+7;
int n,L,R;
long long f[N][3];

signed main() {
	scanf("%I64d%I64d%I64d",&n,&L,&R);
	long long c0=R/3-(L-1)/3,c1=(R+1)/3-L/3,c2=(R+2)/3-(L+1)/3;
	f[1][0]=c0,f[1][1]=c1,f[1][2]=c2;
	for(int i=2;i<=n;++i) {
		f[i][0]=(f[i-1][0]*c0%mod+f[i-1][1]*c2%mod+f[i-1][2]*c1%mod)%mod;
		f[i][1]=(f[i-1][0]*c1%mod+f[i-1][1]*c0%mod+f[i-1][2]*c2%mod)%mod;
		f[i][2]=(f[i-1][0]*c2%mod+f[i-1][1]*c1%mod+f[i-1][2]*c0%mod)%mod;
	}
	printf("%I64d\n",f[n][0]);
   // system("pause");
	return 0;
}