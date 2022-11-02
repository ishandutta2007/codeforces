#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define pf emplace_front
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int n;LL x;DB goal,nxt;
int f[70][45][35][30];

inline void upmin(int &x,int y){
	if(x > y) x = y;
}

inline int pd(int i,int j,int k,int l){
	DB t = x;
	FOR(x,1,i){
		if(t*2 >= nxt) return -1;
		t *= 2;
	}
	FOR(x,1,j){
		if(t*3 >= nxt) return -1;
		t *= 3;
	}
	FOR(x,1,k){
		if(t*5 >= nxt) return -1;
		t *= 5;
	}
	FOR(x,1,l){
		if(t*7 >= nxt) return -1;
		t *= 7;
	}
	return t >= goal;
}

bool vis[10];

inline void getd(int i,int j,int k,int l){
	CLR(vis,0);
	unsigned LL t = x;
	FOR(x,1,i) t *= 2;
	FOR(x,1,j) t *= 3;
	FOR(x,1,k) t *= 5;
	FOR(x,1,l) t *= 7;
	while(t){
		vis[t%10] = 1;
		t /= 10;
	}
}

const int prime[4] = {2,3,5,7};
int dx[4];

int main(){
	scanf("%d%lld",&n,&x);CLR(f,0x3f);
	goal = 1;FOR(i,1,n-1) goal *= 10;nxt = goal*10;
	f[0][0][0][0] = 0;int ans = 0x3f3f3f3f;
	FOR(i,0,69) FOR(j,0,44) FOR(k,0,34) FOR(l,0,29){
		int now = f[i][j][k][l];
		if(now == 0x3f3f3f3f) continue;
		int t = pd(i,j,k,l);
		if(t == 1){
			upmin(ans,now);
			break;
		}
		if(t == -1) break;
		getd(i,j,k,l);
		FOR(x,2,9){
			if(vis[x]){
				CLR(dx,0);int t = x;
				FOR(y,0,3) if((t%prime[y]) == 0){
					while(!(t%prime[y])) dx[y]++,t /= prime[y];
				}
				upmin(f[i+dx[0]][j+dx[1]][k+dx[2]][l+dx[3]],now+1);
			}
		}
	}
	if(ans == 0x3f3f3f3f) ans = -1;
	printf("%d\n",ans);
	return 0;
}