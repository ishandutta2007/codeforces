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

const int MAXN = 300+5;

int n;
char str[MAXN];

inline int query(){
	FOR(i,1,n) putchar(str[i]);puts("");std::fflush(stdout);
	int x;scanf("%d",&x);
	if(!x) exit(0);
	return x; 
}

int main(){
	FOR(i,1,300) putchar('a');puts("");std::fflush(stdout);
	int ra;scanf("%d",&ra);
	if(!ra) exit(0);
	FOR(i,1,300) putchar('b');puts("");std::fflush(stdout);
	int rb;scanf("%d",&rb);
	if(!rb) exit(0);
	n = 600-ra-rb;
	int ca = rb-300+n,cb = ra-300+n;
	FOR(i,1,n) str[i] = 'a';
	FOR(i,1,n-1){
		str[i] = 'b';
		int t = query();
		if(t == cb+1){
			str[i] = 'a';
		}
		else --cb;
	}
	if(cb) str[n] = 'b';
	query();
	return 0;
}