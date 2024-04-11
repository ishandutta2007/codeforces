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
const int MAXM = 1e7 + 6;
int a[MAXN],b[MAXN];
int n,m;
bool p[MAXM];
int prime[MAXM],cnt;
int d[MAXM];

inline void prework(){
	FOR(i,2,MAXM-1){
		if(!p[i]) prime[++cnt] = i,d[i] = cnt;
		for(int j = 1;j <= cnt && 1ll*i*prime[j] < MAXM;++j){
			p[i*prime[j]] = 1;
			d[i*prime[j]] = j;
			if(!(i%prime[j])){
				d[i*prime[j]] = std::min(d[i*prime[j]],j);
				break;
			}
		}
	}
}

int f[MAXM];
std::vector<int> G[700000+5];

int main(){prework();
	scanf("%d%d",&n,&m);
	// DEBUG(d[10]);
	FOR(i,1,n){
		int x;scanf("%d",&x);a[i] = x;
		while(x != 1){
			f[d[x]]++;
			G[d[x]].pb(i);
			x /= prime[d[x]];
		}
	}
	// exit(0);
	FOR(i,1,m){
		int x;scanf("%d",&x);b[i] = x;
		while(x != 1){
			f[d[x]]--;
			if(G[d[x]].size()){
				b[i] /= prime[d[x]];
				a[G[d[x]].back()] /= prime[d[x]];
				G[d[x]].pop_back();
			}
			x /= prime[d[x]];
		}
	}
	printf("%d %d\n",n,m);
	FOR(i,1,n) printf("%d ",a[i]);puts("");
	FOR(i,1,m) printf("%d ",b[i]);puts("");
	return 0;
}