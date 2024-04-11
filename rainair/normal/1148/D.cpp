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

const int MAXN = 6e5 + 5;
int n;
std::vector<P> v1,v2;

int id[MAXN];

inline bool cmp1(P a,P b){
	return a.se > b.se;
}

inline bool cmp2(P a,P b){
	return a.se < b.se;
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		int a,b;scanf("%d%d",&a,&b);id[a] = id[b] = i;
		if(a < b) v1.pb(MP(a,b));
		else v2.pb(MP(a,b));
	}
	std::sort(all(v1),cmp1);
	std::sort(all(v2),cmp2);
	if(v1.size() > v2.size()){
		printf("%d\n",(int)v1.size());
		for(auto x:v1) printf("%d ",id[x.fi]);
		return 0;
	}
	else{
		printf("%d\n",(int)v2.size());
		for(auto x:v2) printf("%d ",id[x.fi]);
	}
	return 0;
}