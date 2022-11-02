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
LL sm[MAXN],mx[MAXN];
int ps[MAXN];
int n,s;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&s);
		FOR(i,1,n){
			LL x;scanf("%lld",&x);
			sm[i] = sm[i-1]+x;
			if(mx[i-1] < x) mx[i] = x,ps[i] = i;
			else mx[i] = mx[i-1],ps[i] = ps[i-1];
		}
		if(sm[n] <= s) puts("0");
		else{
			int ans = 0;
			FOR(i,1,n){
				if(sm[i]-mx[i] <= s) ans = ps[i];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}