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

const int MAXN = 5000+5;
char str[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",str+1);int n = strlen(str+1);
		bool flag = 1;
		FOR(i,2,n) flag &= (str[i] == str[i-1]);
		if(flag) printf("%s\n",str+1);
		else{
			FOR(i,1,n){
				printf("10");
			}
			puts("");
		}
	}
	return 0;
}