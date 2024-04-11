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
int na,nb,nc;
int a[MAXN],b[MAXN],c[MAXN];

#define pw(x) ((x)*(x))

inline LL calc(LL a,LL b,LL c){
//	printf("%lld %lld %lld\n",a,b,c);
	return pw(a-b)+pw(b-c)+pw(c-a);
}

inline LL work(int na,int nb,int nc,int a[],int b[],int c[]){
	// na <= nb <= nc
	int p1 = 0,p2 = 1;
	LL ans = 3e18;
	FOR(i,1,nb){
		while(p1 < na && a[p1+1] <= b[i]) p1++;
		while(p2 <= nc && c[p2] < b[i]) p2++;
		if(p1 >= 1 && p2 <= nc) ans = std::min(ans,calc(a[p1],b[i],c[p2]));
	}
	return ans;
}

inline void Solve(){
	scanf("%d%d%d",&na,&nb,&nc);
	FOR(i,1,na) scanf("%d",a+i);
	FOR(i,1,nb) scanf("%d",b+i);
	FOR(i,1,nc) scanf("%d",c+i);
	std::sort(a+1,a+na+1);std::sort(b+1,b+nb+1);std::sort(c+1,c+nc+1);
	LL res = 3e18;
	res = std::min(res,work(na,nb,nc,a,b,c));
	res = std::min(res,work(na,nc,nb,a,c,b));
	res = std::min(res,work(nb,na,nc,b,a,c));
	res = std::min(res,work(nb,nc,na,b,c,a));
	res = std::min(res,work(nc,na,nb,c,a,b));
	res = std::min(res,work(nc,nb,na,c,b,a));
	printf("%lld\n",res); 
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}
/*
1
1 1 1
1
1
1000000000
*/