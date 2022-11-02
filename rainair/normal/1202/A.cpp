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
char a[MAXN],b[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",a+1);
		scanf("%s",b+1);
		int la = strlen(a+1),lb = strlen(b+1);
		while(b[lb] != '1') --lb;
		lb += strlen(a+1)-strlen(b+1);
		while((la > lb || a[la] != '1')&&la>=0) la--;
		if(la < 0){
			puts("0");
			continue;
		}
		printf("%d\n",lb-la);
	}
	return 0;
}