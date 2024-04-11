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

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int n,m;
int a[MAXN];
struct Node{
	int a,b,id;
	bool operator < (const Node &t) const {
		return b < t.b;
	}
}q[MAXN];
int ans[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",a+i);std::sort(a+1,a+n+1);
	FOR(i,1,m) scanf("%d%d",&q[i].a,&q[i].b),q[i].id = i;
	std::sort(q+1,q+m+1);
	int tp = 1;int sm1=0,sm2=0;
	FOR(i,1,n) (sm2 += a[i]%ha) %= ha;
	FOR(i,1,m){
		while(tp <= n && a[tp] < q[i].b){
			(sm1 += a[tp]%ha) %= ha;
			(sm2 += ha-a[tp]%ha) %= ha;
			++tp;
		}
		// if(q[i].a == 0){
			// ans[q[i].id] = (sm1+sm2)%ha;
			// continue;
		// }
		if(q[i].a > n-tp+1){
			ans[q[i].id] = 0;
			continue;
		}
		ans[q[i].id] = 1ll*qpow(n-tp+2)*(n-tp+2-q[i].a)%ha*sm1%ha;
		(ans[q[i].id] += 1ll*qpow(n-tp+1)*((n-tp+1)-q[i].a)%ha*sm2%ha) %= ha;
	}
	FOR(i,1,m) printf("%d\n",ans[i]);
	return 0;
}