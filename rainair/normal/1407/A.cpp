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

const int MAXN = 1e3 + 5;
int n,a[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int cnt1 = 0,cnt0 = 0;
		FOR(i,1,n) scanf("%d",a+i),cnt1 += a[i];
		cnt0 = n-cnt1;
		if(cnt0 >= n/2){
			printf("%d\n",n/2);
			FOR(i,1,n/2) printf("0 ");
			puts("");
			continue;
		}
		if(n%4 == 0){
			printf("%d\n",n/2);
			FOR(i,1,n/2) printf("1 ");
			puts("");continue;
		}
		printf("%d\n",n/2+1);
		FOR(i,1,n/2+1) printf("1 ");
		puts("");continue;
	}
	return 0;
}