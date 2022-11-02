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

const int MAXN = 1e6 + 5;
int n;
bool used[MAXN];

inline int solve(int n){
	int ans = 0;
	CLR(used,0);
	FOR(a,0,n){
		FOR(b,0,n-a){
			FOR(c,0,n-a-b){
				int d = n-a-b-c;
				int x = a+5*b+10*c+d*50;
				if(!used[x]) used[x] = 1,ans++;
			}
		}
	}
	return ans;
}
int aa[MAXN];
int main(){
	scanf("%d",&n);
	if(n <= 50) printf("%d\n",solve(n));
	else printf("%lld\n",solve(50)+1ll*(n-50)*49);
	return 0;
}