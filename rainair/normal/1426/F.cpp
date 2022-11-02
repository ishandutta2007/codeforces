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
const int ha = 1e9 + 7;

char str[MAXN];
int f[MAXN][4];
int n;

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

int main(){
	scanf("%d",&n);scanf("%s",str+1);
	f[0][0] = 1;
	FOR(i,1,n){
		FOR(j,0,3) f[i][j] = 1ll*f[i-1][j]*(str[i]=='?'?3:1)%ha;
		if(str[i] == 'a') add(f[i][1],f[i-1][0]);
		if(str[i] == 'b') add(f[i][2],f[i-1][1]);
		if(str[i] == 'c') add(f[i][3],f[i-1][2]);
		if(str[i] == '?') add(f[i][1],f[i-1][0]),add(f[i][2],f[i-1][1]),add(f[i][3],f[i-1][2]);
	}
	int ans = f[n][3];
	printf("%d\n",ans);
	return 0;
}