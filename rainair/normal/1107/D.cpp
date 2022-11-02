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

const int MAXN = 5200+5;
int n;
bool vis[MAXN][MAXN];
char str[MAXN];
int sm[MAXN][MAXN];

inline int ctoi(char x){
	if('0' <= x && x <= '9') return x-'0';
	return 10+x-'A';
}

inline int calc(int x1,int y1,int x2,int y2){
	return sm[x2][y2]-sm[x1-1][y2]-sm[x2][y1-1]+sm[x1-1][y1-1];
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%s",str+1);
		int t = 0;
		FOR(j,1,n/4){
			int x = ctoi(str[j]);
			vis[i][++t] = (x>>3)&1;
			vis[i][++t] = (x>>2)&1;
			vis[i][++t] = (x>>1)&1;
			vis[i][++t] = x&1;
		}
	}
	FOR(i,1,n) FOR(j,1,n) sm[i][j] = sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1]+vis[i][j];
	// FOR(i,1,n) FOR(j,1,n) printf("%d%c",vis[i][j]," \n"[j==n]);
	ROF(x,n,2){
		if(n%x) continue;
		bool flag = 1;int lim = x*x;
		for(int i = x;i <= n;i += x){
			for(int j = x;j <= n;j += x){
				int t = calc(i-x+1,j-x+1,i,j);
				if(t != 0 && t != lim){
					flag = 0;break;
				}
			}
			if(!flag) break;
		}
		if(flag){
			printf("%d\n",x);
			exit(0);
		}
	}
	puts("1");
	return 0;
}