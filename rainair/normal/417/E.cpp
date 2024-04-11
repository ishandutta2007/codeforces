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
int a[MAXN],b[MAXN];

int main(){
	int n,m;scanf("%d%d",&n,&m);
	if(n <= 2){
		if(n == 1) a[1] = 1;
		if(n == 2) a[1] = 3,a[2] = 4;
	}
	else{
		a[1] = n-2;FOR(i,2,n) a[i] = 2;
	}
	if(m <= 2){
		if(m == 1) b[1] = 1;
		if(m == 2) b[1] = 3,b[2] = 4;
	}
	else{
		b[1] = m-2;FOR(i,2,m) b[i] = 2;
	}
	FOR(i,1,n){
		FOR(j,1,m){
			printf("%d ",a[i]*b[j]);
		}
		puts("");
	}
	return 0;
}