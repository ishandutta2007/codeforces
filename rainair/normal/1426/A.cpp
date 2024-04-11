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
	int T;scanf("%d",&T);
	while(T--){
		int n,x;scanf("%d%d",&n,&x);
		int l = 1,r = 2;
		FOR(i,1,n){
			if(l <= n && n <= r){
				printf("%d\n",i);break;
			}
			l = r+1;r = l+x-1;
		}
	}
	return 0;
}