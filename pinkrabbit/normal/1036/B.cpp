#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int T; scanf("%d",&T);
	while(T--){
		LL n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		if(k<max(n,m)) {puts("-1"); continue;}
		if((n+m)&1) printf("%lld\n",k-1);
		else{
			if((n+k)&1) printf("%lld\n",k-2);
			else printf("%lld\n",k);
		}
	}
	return 0;
}