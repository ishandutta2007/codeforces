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

const int MAXN = 500+5;
int n;
int a[MAXN];
std::multiset<int> S;

int main(){
	scanf("%d",&n);
	FOR(i,1,n) FOR(j,1,n){
		int x;scanf("%d",&x);S.insert(x);
	}
	FOR(i,1,n){
		int p = *S.rbegin();
		a[i] = p;
		FOR(j,1,i-1){
			int g = std::__gcd(a[j],a[i]);
			FOR(k,0,1) S.erase(S.find(g));
		}
		S.erase(S.find(p));
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}