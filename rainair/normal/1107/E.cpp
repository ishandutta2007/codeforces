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

int n;
char str[MAXN];
LL a[MAXN];int b[MAXN];
LL f[MAXN][MAXN][MAXN];// [l,r],lk

inline void upmax(LL &x,LL y){
	if(x < y) x = y;
}

int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	FOR(i,1,n) scanf("%lld",b+i);
	FOR(i,1,n){
		FOR(j,0,i-1){
			upmax(a[i],a[j]+b[i-j]);
		}
	}
	CLR(f,~0x3f);
	FOR(i,1,n){
		FOR(j,0,n-1) f[i][i][j] = a[j+1];
		f[i][i-1][0] = 0;
	}
	FOR(len,2,n){
		FOR(l,1,n-len+1){
			int r = l+len-1;
			FOR(k,0,n){
				upmax(f[l][r][k],f[l+1][r][0]+a[k+1]);
				FOR(x,l+1,r){
					if(str[x] == str[l]) upmax(f[l][r][k],f[l+1][x-1][0]+f[x][r][k+1]);
				}
			}
		}
	}
	// DEBUG(f[1][7][0]);
	// DEBUG(f[2][7][1]);
	// DEBUG(f[4][7][2]);
	printf("%lld\n",f[1][n][0]);
	return 0;
}
/*
+dp
 str[l]==str[x]
f[l][r][k] = f[l+1][x-1][0]+f[x][r][k+1]
f[l][r][k] = f[l][r][0]+a[k+1]
*/