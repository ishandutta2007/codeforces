#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define uLL unsigned LL
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3000+5;
const int ha = 1e9 + 7;
const int BASE = 31;
const int BLO = 19260817;

struct Edge{
	uLL val;int nxt;
}e[MAXN*MAXN];int cnt;
int head[BLO];
int n;
std::unordered_map<uLL,int> S;
int a[MAXN];
int f[MAXN][MAXN];// [l,r]

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

int t[4][4];

inline bool chk(int l,int r){
	FOR(i,0,3){
		bool flag = 1;
		FOR(j,0,3) flag &= t[i][j]==a[l+j];
		if(flag) return 1;
	}
	return 0;
}

uLL pre[MAXN],pw[MAXN];

inline uLL calc(int l,int r){
	return pre[r]-pre[l-1]*pw[r-l+1];
}

inline bool find(uLL x){
	int y = x%BLO;
	// DEBUG(y);
	for(int i = head[y];i;i = e[i].nxt) if(e[i].val == x) return 1;
	return 0;
}

inline void ins(uLL x){
	int y = x%BLO;
	e[++cnt] = (Edge){x,head[y]};head[y] = cnt;
}

int main(){
	t[0][0] = 0;t[0][1] = 0;t[0][2] = 1;t[0][3] = 1;
	t[1][0] = 0;t[1][1] = 1;t[1][2] = 0;t[1][3] = 1;
	t[2][0] = 1;t[2][1] = 1;t[2][2] = 1;t[2][3] = 0;
	t[3][0] = 1;t[3][1] = 1;t[3][2] = 1;t[3][3] = 1;
	scanf("%d",&n);pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = pw[i-1]*BASE;
	FOR(i,1,n) scanf("%d",a+i);int ans = 0;
	FOR(i,1,n) pre[i] = pre[i-1]*BASE+(a[i]+1);
	FOR(i,1,n){
		f[i][i-1] = 1;
		ROF(j,i,1){
			FOR(k,1,4){
				if(i-k < j-1) break;
				if(k == 4 && chk(i-3,i)) continue;
				add(f[j][i],f[j][i-k]);
			}
			uLL t = calc(j,i);
			
			if(find(t)) continue;
			// S[t] = 1;
			ins(t);
			add(ans,f[j][i]);
		}
		printf("%d\n",ans);
		// if(i == 3) exit(0);
	}
	return 0;
}