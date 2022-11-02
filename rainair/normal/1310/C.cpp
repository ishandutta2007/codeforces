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
const LL INF = 4e18;

int n,m;LL k;
char str[MAXN];
int lcp[MAXN][MAXN];
std::vector<P> S;

inline bool cmp(P a,P b){
	int lcp = ::lcp[a.fi][b.fi];
	if(a.fi+lcp > a.se || b.fi+lcp > b.se) return a.se-a.fi < b.se-b.fi;
	return str[a.fi+lcp] < str[b.fi+lcp];
}

LL f[MAXN][MAXN];
// lcp

inline bool chk(int l,int r){
	CLR(f,0);
	f[0][n+1] = 1;int len = r-l+1;
	FOR(i,1,m){
		ROF(j,n,0){
			f[i-1][j] += f[i-1][j+1];
			if(f[i-1][j] >= INF) f[i-1][j] = INF;
		}
		ROF(j,n-i+1,1){
			int lcp = ::lcp[l][j];
			// if(i == 1 && j == 1){
				// DEBUG(lcp);
			// }
			if(lcp < r-l+1){
				if(str[j+lcp] > str[l+lcp]){
					f[i][j] += f[i-1][j+lcp+1];
					if(f[i][j] >= INF) f[i][j] = INF;
				}
			}
			else{
				lcp = std::min(lcp,r-l+1);
				f[i][j] += f[i-1][j+lcp];
				if(f[i][j] >= INF) f[i][j] = INF;
			}
		}
		// if(i == 1){
			// DEBUG(f[i][1]);
		// }
	}
	// DEBUG(f[1][4]-f[0][]);
	// DEBUG(f[m][1]);
	return f[m][1] >= k;
}

int main(){
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%s",str+1);
	ROF(i,n,1){
		ROF(j,n,1){
			if(str[i] == str[j]) lcp[i][j] = lcp[i+1][j+1]+1;
			else lcp[i][j] = 0;
		}
	}
	FOR(i,1,n) FOR(j,i,n) S.pb(MP(i,j));
	std::sort(all(S),cmp);
	// DEBUG(chk(S[1545].fi,S[1545].se));
	// exit(0);
	int l = 0,r = (int)S.size()-1,ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(chk(S[mid].fi,S[mid].se)) ans = mid,l = mid+1;
		else r = mid-1;
	}
	// DEBUG(chk(S[5348].fi,S[5348].se));
	// DEBUG(ans);
	// FOR(i,0,(int)S.size()-1){
		// if(S[i].fi+1 == S[i].se && str[S[i].fi] == 'k' && str[S[i].se] == 'b') DEBUG(i);
	// }
	// DEBUG(ans);exit(0);
	FOR(i,S[ans].fi,S[ans].se) putchar(str[i]);puts("");
	return 0;
}