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
int n,s,deg[MAXN];

int main(){
	scanf("%d%d",&n,&s);
	FOR(i,2,n){
		int u,v;scanf("%d%d",&u,&v);
		++deg[u];++deg[v];
	}
	int t = 0;
	FOR(i,1,n) t += (deg[i]==1);
	printf("%.20f\n",2.0*s/t);
	return 0;
}