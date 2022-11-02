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
int c[MAXN],d[MAXN],n;

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d",c+i,d+i);
	int l = -1e9,r = 1e9,sm = 0;
	if(d[1] == 1) l = std::max(l,1900);
	else r = std::min(r,1899);
	FOR(i,1,n){
		sm += c[i];
		if(i == n) break;
		if(d[i+1] == 1){ // x+sm >= 1900
			l = std::max(l,1900-sm);
		}
		else{ // x<= 1899-sm
			r = std::min(r,1899-sm);
		}
	}
	DEBUG(l);DEBUG(r);
	if(l > r){
		puts("Impossible");
		return 0;
	}
	if(r == 1e9){
		puts("Infinity");
		return 0;
	}
	printf("%d\n",r+sm);
	return 0;
}