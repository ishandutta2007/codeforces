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

const int MAXN = 3e5 + 5;
int n,x,y;
char str[MAXN];

int main(){
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",str+1);int m = 0;
	str[0] = '1';
	FOR(i,1,n){
		if(str[i-1] == '1' && str[i] == '0') ++m;
	}
	if(m == 0){
		puts("0");
		return 0;
	}
	printf("%lld\n",std::min(1ll*m*y,1ll*(m-1)*x+y));
	return 0;
}