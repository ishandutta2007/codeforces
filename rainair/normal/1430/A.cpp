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

const int MAXN = 1000+5;
int a[MAXN],b[MAXN],c[MAXN];
bool f[MAXN];

int main(){
	a[0] = b[0] = c[0] = 0;f[0] = 1;
	
	FOR(i,1,1000){
		if(i-3 >= 0 && f[i-3]){
			f[i] = f[i-3];
			a[i] = a[i-3]+1;
			b[i] = b[i-3];c[i] = c[i-3];
			continue;
		}
		if(i-5 >= 0 && f[i-5]){
			f[i] = 1;
			a[i] = a[i-5];
			b[i] = b[i-5]+1;
			c[i] = c[i-5];
		}
		if(i-7 >= 0 && f[i-7]){
			f[i] = 1;
			a[i] = a[i-7];
			b[i] = b[i-7];
			c[i] = c[i-7]+1;
		}
	}
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		if(f[n]){
			printf("%d %d %d\n",a[n],b[n],c[n]);
		}
		else{
			printf("%d\n",-1);
		}
	}
	return 0;
}