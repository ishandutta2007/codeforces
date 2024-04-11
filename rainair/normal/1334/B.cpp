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

const int MAXN = 1e5 + 5;

int a[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,x;scanf("%d%d",&n,&x);
		FOR(i,1,n) scanf("%d",a+i);
		std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
		LL sm = 0;
		bool flag = 0;
		FOR(i,1,n){
			sm += a[i];
			if(sm < 1ll*i*x){
				printf("%d\n",i-1);flag = 1;
				break;
			}
		}
		if(!flag) printf("%d\n",n);
	}
	return 0;
}