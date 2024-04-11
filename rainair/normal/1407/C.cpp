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

inline int query(int x,int y){
	printf("? %d %d\n",x,y);std::fflush(stdout);
	int res;scanf("%d",&res);return res;
}

const int MAXN = 1e5 + 5;
int p[MAXN];bool vis[MAXN];

int main(){
	int n;scanf("%d",&n);
	int las = 1;
	FOR(i,2,n){
		int t1 = query(las,i),t2 = query(i,las);
		if(t1 > t2) p[las] = t1,las = i;
		else p[i] = t2;
	}
	FOR(i,1,n) vis[p[i]] = 1;
	FOR(i,1,n) if(!vis[i]) p[las] = i;
	putchar('!');
	FOR(i,1,n) printf(" %d",p[i]);
	puts("");std::fflush(stdout);
	return 0;
}