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

const int MAXN = 3500+5;
const int ha = 1e9 + 7;
const int inv2 = (ha+1)>>1;
int p,_,n;
char str[MAXN];
int b[MAXN],a[MAXN];
int f[2][MAXN][2][2],now;
// i j  

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

inline int calc(int n){ // [x+y <= n]
	if(n < 0) return 0;
	if(n == 0) return 1;
	return (1ll*(n+1)*(n+1)%ha+ha-1ll*n*(n+1)%ha*inv2%ha)%ha;
}

inline int calc2(int n){
	// p <= n+1-i => i <= n+1-p
	int res = 0;
	if(n+1-p >= 0) add(res,1ll*(n+1-p+1)%ha*p%ha);
	// p > n+1-i => i >= n+2-p
	if(n+2-p <= p-1){
		// p-1 +p-2 + ....
		int len = (p-1)-(n+2-p)+1;
		add(res,1ll*(p-1)*p%ha*inv2%ha);
		len = (p-1)-len;
		if(len > 0) add(res,ha-1ll*(len+1)*len%ha*inv2%ha);
	}
	return res;
}

int main(){
	scanf("%d%d",&p,&_);// 
	scanf("%s",str+1);int len = strlen(str+1);
	FOR(i,1,len) a[i] = str[i]-'0';
	std::reverse(a+1,a+len+1);
	while(len){
		int t = 0;
		ROF(i,len,1) t = (10ll*t+a[i]) % p;
		b[++n] = t;
		a[1] -= t;
		FOR(i,1,len){
			if(a[i] < 0){
				int tt = (-a[i])/10;
				if(a[i]+10*tt < 0) ++tt;
				a[i] += 10*tt;
				a[i+1] -= tt;
			}
		}
		while(len && !a[len]) --len;
		LL r = 0; // up to O(p^2)
		ROF(i,len,1){
			r = 10*r+a[i];
			a[i] = r/p;
			r %= p;
		}
		while(len && !a[len]) --len;
	}
	std::reverse(b+1,b+n+1);
	f[now=0][0][1][0] = 1;
	// int tt = 0;FOR(x,0,p-1) FOR(y,0,p-1) tt += (x+y <= 3);
	// DEBUG(tt);DEBUG(calc2(3));
	// DEBUG(calc2(3)-calc2(2));
	// exit(0);
	FOR(i,1,n){
		//  <=> (x+y)%p < b[i]
		//   <=>  x+y>=p
		//  <=> x+y <= p-1
		//  <=> (x+y)%p = b[i]
		// +1 <=>  +1=
		//  
		// (x+1)^2-x*(x+1)/2
		CLR(f[now^1],0);
		FOR(j,0,i){// x,y
			// [x+y <= p-1]
			// int c1 = 1ll*p*p%ha;add(c1,ha-1ll*p*(p-1)%ha*inv2%ha);
			int t = 0;
			int c1 = calc(p-1);
			// t = 0;FOR(i,0,p-1) FOR(j,0,p-1) if(i+j < p) ++t;
			// DEBUG(c1);DEBUG(t);
			// assert(c1 == t);
			int c2 = calc(p-2);
			// t = 0;FOR(i,0,p-1) FOR(j,0,p-1) if(i+j >= p) ++t;
			// assert(c2 == t);
			int c3 = calc(b[i]-1);
			// t = 0;FOR(x,0,p-1) FOR(y,0,p-1) if(x+y < p && (x+y)%p < b[i]) ++t;
			// assert(c3==t);
			int c4 = (calc2(p+b[i]-1)+ha-calc2(p-1))%ha;
			// t = 0;FOR(x,0,p-1) FOR(y,0,p-1) if(x+y >= p && (x+y)%p < b[i]) ++t;
			// DEBUG(c4);DEBUG(t);
			// exit(0);
			// assert(c4==t);
			add(f[now^1][j][0][0],1ll*f[now][j][0][0]*(c1/**/)%ha);
			add(f[now^1][j][0][0],1ll*f[now][j][0][1]*(c2/**/)%ha);
			add(f[now^1][j][0][0],1ll*f[now][j][1][0]*(c3/* */)%ha);
			add(f[now^1][j][0][0],1ll*f[now][j][1][1]*(c4/* */)%ha);
			c1 = calc(p-2);
			// t = 0;FOR(i,0,p-1) FOR(j,0,p-1) if(i+j+1 <= p-1) ++t;
			// assert(t==c1);
			c2 = calc(p-2);add(c2,p);
			// t = 0;FOR(i,0,p-1) FOR(j,0,p-1) if(i+j+1 >= p) ++t;
			// assert(t==c2);
			c3 = calc(b[i]-2);
			// t = 0;FOR(x,0,p-1) FOR(y,0,p-1) if(x+y+1 < p && (x+y+1)%p < b[i]) ++t;
			// assert(t==c3);
			c4 = (calc2(std::min(2*p-2,b[i]+p-2))+ha-calc2(p-2))%ha;
			
			// t = 0;FOR(x,0,p-1) FOR(y,0,p-1) if(x+y+1 >= p && (x+y+1)%p < b[i]) ++t;//,DEBUG(x),DEBUG(y);
			// DEBUG(t);DEBUG(c4);
			// exit(0);
			// assert(t==c4);
			add(f[now^1][j+1][0][1],1ll*f[now][j][0][0]*(c1/* +1*/)%ha);
			add(f[now^1][j+1][0][1],1ll*f[now][j][0][1]*(c2/* +1*/)%ha);
			add(f[now^1][j+1][0][1],1ll*f[now][j][1][0]*(c3/*  +1*/)%ha);
			add(f[now^1][j+1][0][1],1ll*f[now][j][1][1]*(c4/*  +1*/)%ha);
			
			// t = 0;FOR(x,0,p-1) FOR(y,0,p-1) if(x+y < p && (x+y)%p == b[i]) ++t;
			c3 = b[i]+1;
			// DEBUG(c3);DEBUG(t);
			// assert(c3==t);
			c4 = std::min(b[i]+p,p-1)-std::max(1+b[i],0)+1;
			c4 = std::max(c4,0);
			// t = 0;FOR(x,0,p-1) FOR(y,0,p-1) if(x+y >= p && (x+y)%p == b[i]) ++t;
			// DEBUG(c4);DEBUG(t);
			// exit(0);
			// assert(t==c4);
			// if(i == 2 && j == 1) DEBUG(c4);
			// add(f[now^1][j][1][0],f[now][j][0][0]*(/**/));
			// add(f[now^1][j][1][0],f[now][j][0][1]*(/**/));
			add(f[now^1][j][1][0],1ll*f[now][j][1][0]*(c3/* */)%ha);
			add(f[now^1][j][1][0],1ll*f[now][j][1][1]*(c4/* */)%ha);
			
			c3 = b[i]-1+1;
			// t = 0;FOR(x,0,p-1) FOR(y,0,p-1) if(x+y+1 < p && (x+y+1)%p == b[i]) ++t;
			// assert(c3==t);
			
			
			c4 = std::min(b[i]+p-1,p-1)-std::max(1-p+b[i]+p-1,0)+1;
			// t = 0;FOR(x,0,p-1) FOR(y,0,p-1) if(x+y+1 >= p && (x+y+1)%p == b[i]) ++t;
			// DEBUG(c4);DEBUG(t);
			// exit(0);
			// assert(c4==t);
			// add(f[now^1][j+1][1][1],f[now][j][0][0]*(/**/));
			// add(f[now^1][j+1][1][1],f[now][j][0][1]*(/**/));
			add(f[now^1][j+1][1][1],1ll*f[now][j][1][0]*(c3/*  +1*/)%ha);
			add(f[now^1][j+1][1][1],1ll*f[now][j][1][1]*(c4/*  +1*/)%ha);
		}
		now ^= 1;
		// FOR(j,0,i) printf("%d %d %d %d\n",f[now][j][0][0],f[now][j][0][1],f[now][j][1][0],f[now][j][1][1]);
		// puts("");
	}
	int ans = 0;
	FOR(i,_,n) add(ans,f[now][i][0][0]),add(ans,f[now][i][1][0]);
	printf("%d\n",ans);
	return 0;
}