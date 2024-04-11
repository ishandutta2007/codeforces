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

const int MAXN = 100+5;
const int ha = 998244353;
int l[MAXN],r[MAXN];
int n;
std::vector<int> S;
int f[MAXN][MAXN];
int inv[MAXN];

inline int C(int n,int m){
	if(n < 0 || m < 0 || n < m) return 0;
	int ans = 1;
	FOR(i,1,m) ans = 1ll*ans*(n-i+1)%ha;
	FOR(i,1,m) ans = 1ll*ans*inv[i]%ha;
	return ans;
}

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

int main(){
	inv[1] = 1;FOR(i,2,MAXN-1) inv[i] = ha-1ll*(ha/i)*inv[ha%i]%ha;
	scanf("%d",&n);int t = 1;
	ROF(i,n,1){
		scanf("%d%d",l+i,r+i);S.pb(l[i]-1);S.pb(r[i]);
		t = 1ll*t*(r[i]-l[i]+1)%ha;
	}
	t = qpow(t);
	std::sort(all(S));S.erase(std::unique(all(S)),S.end());
	FOR(i,1,n){
		l[i] = std::lower_bound(all(S),l[i]-1)-S.begin()+1;
		r[i] = std::lower_bound(all(S),r[i])-S.begin()+1;
	}
	f[0][0] = 1;
	int m = S.size();
	FOR(i,1,m){
		FOR(j,0,n){
			bool flag = (i > l[j] && i <= r[j]);
			f[i][j] = f[i-1][j];
			ROF(k,j-1,0){
				if(!flag) break;
				int len = i==1?S[i-1]:S[i-1]-S[i-2];
				// add(f[i][j],1ll*f[i-1][k]*C(j-k+len-1,len-1)%ha);
				add(f[i][j],1ll*f[i-1][k]*C(j-k+len-1,j-k)%ha);
				flag &= (i > l[k] && i <= r[k]);	
			}
		}
	}
	int ans = f[m][n];
	// 457137
	ans = 1ll*ans*t%ha;
	printf("%d\n",ans);
	return 0;
}