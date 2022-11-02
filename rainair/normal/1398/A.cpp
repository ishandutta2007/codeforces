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

const int MAXN = 1e5 +5;
int a[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		FOR(i,1,n) scanf("%d",a+i);
		if(a[1]+a[2] <= a[n]) printf("1 2 %d\n",n);
		else puts("-1");
	} 
	return 0;
}