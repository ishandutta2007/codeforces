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
int n,a[MAXN],b[MAXN],m;

int nxt[MAXN];

inline void build(int str[]){
	int j = 0;
	nxt[1] = 0;
	FOR(i,2,m){
		while(j && str[i] != str[j+1]) j = nxt[j];
		if(str[i] == str[j+1]) ++j;
		nxt[i] = j;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	if(m == 1){
		printf("%d\n",n);
		return 0;
	}
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,m) scanf("%d",b+i);
	FOR(i,1,n) a[i] -= a[i+1];
	FOR(i,1,m) b[i] -= b[i+1];
	--n;--m;
	build(b);
	int j = 0,ans = 0;
	FOR(i,1,n){
		while(j && a[i] != b[j+1]) j = nxt[j];
		if(a[i] == b[j+1]) ++j;
		if(j == m){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}