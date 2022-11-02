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

const int MAXN = 1000+5;
int a[MAXN],n,b[MAXN];
bool vis[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		FOR(i,1,n) scanf("%d",a+i),vis[i] = 0;
		int now = 0;
		FOR(i,1,n){
			int mx = 0,ps = -1;
			FOR(j,1,n){
				if(vis[j]) continue;
				int g = std::__gcd(now,a[j]);
				if(g > mx){
					mx = g;ps = j;
				}
			}
			vis[ps] = 1;b[i] = a[ps];printf("%d ",b[i]);
			now = std::__gcd(now,b[i]);
		}
		puts("");
	}
	return 0;
}