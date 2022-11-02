#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
LL f[MAXN][2];
LL r1,r2,r3,d,a[MAXN];
int n;

int main(){
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	FOR(i,1,n) scanf("%lld",a+i);
	FOR(i,1,n){
		LL v1 = r1*a[i]+r3,v2 = std::min(r2+r1,r1*(a[i]+2));
		f[i][0] = f[i][1] = 1e18;
		f[i][0] = std::min(f[i][0],f[i-1][0]+v1);
		f[i][0] = std::min(f[i][0],f[i-1][1]+v2+2*d);
		f[i][1] = std::min(f[i][1],f[i-1][0]+v2);
		if(i == n){
			f[i][0] = std::min(f[i][0],f[i-1][1]+v1+d);
		}
	}
	printf("%lld\n",std::min(f[n][0],f[n][1]+2*d)+(n-1)*d);
	return 0;
}