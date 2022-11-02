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

const int MAXN = 2000+5;
LL a[MAXN];

int main(){
	LL k;scanf("%lld",&k);
	LL x = 0,y = 0,n = 2000;
	for(y=1;y <= 1000000;++y){
		x = (k+y*n)/(n-1);
		if((x-y)*n-x==k) break;
	}
	printf("%lld\n",n);
	FOR(i,1,n-2) a[i] = 0;
	a[n-1] = -y;a[n] = x;
	FOR(i,1,n) printf("%lld%c",a[i]," \n"[i==n]);
	// // assert(1ll*y*(n-1)-1ll*(y-x)*n == k);
	// // DEBUG((x-y)*n-502000);
    // LL res = 0;
    // LL cur = 0;
    // LL kk = 0;
    // DEBUG(1ll*(a[n]+a[n-1])*n);
    // FOR(i,1,n){
        // cur = cur + a[i];
        // if (cur < 0){
            // cur = 0;
            // kk = i;
        // }
        // res = std::max(res, (i-kk)*cur);
        // if(i == n) DEBUG(kk);
    // }
    // printf("%lld\n",res);
	return 0;
}
/*
xn-y=k
*/