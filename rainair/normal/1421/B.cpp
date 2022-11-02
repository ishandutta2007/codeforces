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

const int MAXN = 200+5;
char str[MAXN][MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		FOR(i,1,n) scanf("%s",str[i]+1);
		bool f[5]={0},t[5]={0};
		f[0] = str[1][2] == '0';
		f[1] = str[2][1] == '0';
		f[2] = str[n][n-1]=='0';
		f[3] = str[n-1][n] == '0';
		FOR(S,0,(1<<4)-1){
			if(__builtin_popcount(S) > 2) continue;
			FOR(i,0,3){
				if((S>>i)&1) t[i] = f[i]^1;
				else t[i] = f[i];
			}
			if(t[0] == t[1] && t[2] == t[3] && t[0] != t[2]){
				printf("%d\n",__builtin_popcount(S));
				if(S&1) printf("%d %d\n",1,2);
				if((S>>1)&1) printf("%d %d\n",2,1);
				if((S>>2)&1) printf("%d %d\n",n,n-1);
				if((S>>3)&3) printf("%d %d\n",n-1,n);
				break;
			}
		}
	}
	return 0;
}