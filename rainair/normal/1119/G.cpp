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

const int MAXN = 1e6 + 5;
int n,m;
int a[MAXN];
int b[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m) scanf("%d",a+i);
	int sm = 0;std::vector<int> v1;v1.pb(0);v1.pb(n);
	FOR(i,1,m-1){
		sm += a[i];
		v1.pb(sm%n);
	}
	sm += a[m];
	std::sort(all(v1));std::vector<int> sz;
	FOR(i,1,(int)v1.size()-1) sz.pb(v1[i]-v1[i-1]);
	printf("%d\n",(sm+n-1)/n);
	for(auto x:sz) printf("%d ",x);puts("");
	int p = 0;
	FOR(i,1,m){
		while(a[i] > 0){
			a[i] -= sz[p];++p;
			printf("%d ",i);
			if(p == (int)sz.size()) puts(""),p = 0;
		}
	}
	// DEBUG(sz.size());DEBUG(m);
	if(p) FOR(i,p,m-1) printf("1 ");
	puts("");
	return 0;
}