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
int n;char str[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);scanf("%s",str+1);
		if(n == 2 && str[1] >= str[2]){
			puts("NO");continue;
		}
		puts("YES");
		puts("2");
		putchar(str[1]);putchar(' ');
		FOR(i,2,n) putchar(str[i]);puts("");
	}
	return 0;
}