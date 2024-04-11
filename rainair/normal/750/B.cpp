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

const int MAXN = 50+5;
int n,s;

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		char str[233];int t;
		scanf("%d%s",&t,str+1);
		if(s == 0 && str[1] != 'S'){
			puts("NO");return 0;
		}
		if(s == 20000 && str[1] != 'N'){
			puts("NO");return 0;
		}
		if(str[1] == 'S'){
			s += t;
		}
		if(str[1] == 'N'){
			s -= t;
		}
		if(s < 0 || s > 20000){
			puts("NO");return 0;
		}
	}
	if(s){
		puts("NO");return 0;
	}
	puts("YES");
	return 0;
}