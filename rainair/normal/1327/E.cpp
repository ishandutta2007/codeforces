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

const int MAXN = 2e5 + 5;
const int ha = 998244353;
int n;
int pw[MAXN];

int main(){
	scanf("%d",&n);
	pw[0] = 1;FOR(i,1,MAXN-1) pw[i] =10ll*pw[i-1]%ha;
	FOR(i,1,n){
		if(i == n) printf("%d\n",10);
		else{
			int res = 2ll*10*9%ha*pw[n-i-1]%ha;
			(res += 1ll*(n-i+1-2)*10%ha*9%ha*9%ha*pw[std::max(0,n-i-2)]%ha) %= ha;
			printf("%d ",res);
		}
	}
	return 0;
}