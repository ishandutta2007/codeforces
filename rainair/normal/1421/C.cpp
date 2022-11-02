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

char str[MAXN];

int main(){
	scanf("%s",str+1);int n = strlen(str+1);
	puts("3");
	puts("L 2");
	puts("R 2");
	int len = n+1+n-1;
	printf("R %d\n",len-1);
	return 0;
}