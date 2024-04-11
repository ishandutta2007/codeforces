#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 3000000

LL n,m,f,g,a[N],b[N];

int main(){
	scanf("%lld%lld",&n,&m);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	for (LL i=1;i<=n;++i) scanf("%lld",b+i);
	f=g=0;
	for (LL i=1;i<=n;++i){
		f=max(0LL,f+a[i]-m*b[i]);
		g=max(0LL,g+b[i]-m*a[i]);
		if (f>m||g>m){puts("NO"); return 0;}
	}
	puts("YES");
	
	return 0;
}