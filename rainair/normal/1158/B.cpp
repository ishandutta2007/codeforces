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

int main(){
	int n,k;scanf("%d%d",&n,&k);
	if(n == k){
		FOR(i,1,n) putchar('1');
		return 0;
	}
	if(k == 1){
		FOR(i,1,n-1) putchar('0');
		putchar('1');
		return 0;
	}
	int t = (n-k+2)/2;
	int tt = n/t;
	FOR(i,1,tt){
		putchar('1');
		FOR(j,1,t-1) putchar('0');
	}
	int rr = n-tt*t;
	if(rr) putchar('1'),--rr;
	FOR(i,1,rr) putchar('0');puts("");
	return 0;
}