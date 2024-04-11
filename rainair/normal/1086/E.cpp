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

const int MAXN = 2000+5;
const int ha = 998244353;
int f[MAXN][MAXN];

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

// i j

inline void prework(){
	f[0][0] = 0;
	f[1][0] = 1;f[1][1] = 0;
	FOR(i,2,MAXN-1){
		f[i][0] = 1ll*f[i-1][0]*i%ha;
		FOR(j,1,i){
			f[i][j] = f[i][j-1];
			add(f[i][j],ha-f[i-1][j-1]);
		}
	}
}

int n,a[MAXN][MAXN];
int cnt[MAXN],now;

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	int tree[MAXN];
	
	inline void add(int pos,int x){
		while(pos < MAXN){
			tree[pos] += x;
			pos += lowbit(pos);
		}
	}
	
	inline int query(int pos){
		int res = 0;if(!pos) return 0;
		while(pos){
			res += tree[pos];
			pos -= lowbit(pos);
		}
		return res;
	}
}bit1,bit2;
bool vis[MAXN];
// 1=
// 2=

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

inline void ins(int x,int d){
	++cnt[x];if(cnt[x] == 2) ++now;
	if(d){
		if(cnt[x] == 1) bit1.add(x,1);
		else bit2.add(x,1);
	}
	else{
		if(cnt[x] == 2) bit1.add(x,-1),bit2.add(x,1);
	}
}

int main(){
	prework();
	scanf("%d",&n);FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
	// TODO: 
	int ans = 0;
	ROF(i,n,1){
		// !
		int c = bit1.query(a[1][i]);
		if(c) add(ans,1ll*c*f[n-i][0]%ha);
		bit1.add(a[1][i],1);
	}
	// DEBUG(ans);
	ans = 1ll*ans*qpow(f[n][n],n-1)%ha;
	FOR(i,2,n){
		CLR(cnt,0);CLR(vis,0);CLR(bit1.tree,0);CLR(bit2.tree,0);now = 0;
		int gx = 0;
		ROF(j,n,1){
			/*
			ik,j-k
			 
			*/
			//    /
			ins(a[i-1][j],0);ins(a[i][j],1);
			int t1 = bit1.query(a[i][j]-1),t2 = bit2.query(a[i][j]-1),sz = n-j+1;
			if(cnt[a[i-1][j]] == 2 && a[i-1][j] < a[i][j]) t2--;
			// if(j == 2)DEBUG(sz-1),DEBUG(now);	
			add(gx,1ll*t1*f[sz-1][now-(cnt[a[i-1][j]]==2)]%ha);
			add(gx,1ll*t2*f[sz-1][now-1-(cnt[a[i-1][j]]==2)]%ha);
		}
		// if(i == 2) exit(0);
		gx = 1ll*gx*qpow(f[n][n],n-i)%ha;
		add(ans,gx);
	}
	printf("%d\n",ans);
	return 0;
}
/*
  h(n)
? h(n)^n
i 
 (i,j) ,,

*/