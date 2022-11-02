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
int n,x,a[MAXN],b[MAXN];
std::multiset<int> S;

int main(){
	scanf("%d%d",&n,&x);
	FOR(i,1,n) scanf("%d",a+i);std::sort(a+1,a+n+1);
	FOR(i,1,n) scanf("%d",b+i);std::sort(b+1,b+n+1);
	FOR(i,1,n) S.insert(b[i]);
	int c = 0;
	ROF(i,n,1){
		auto p = S.lower_bound(x-a[i]);
		if(p == S.end()) break;
		S.erase(p);c++;
	}
	printf("%d %d\n",1,c);
	return 0;
}