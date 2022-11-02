#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if (1LL*n*m*2%k==0){
		printf("YES\n");
		printf("0 0\n");
		int tmp=2,tmpp,tn=n,tm=m;
		tmpp=__gcd(tmp,k);
		tmp/=tmpp;
		k/=tmpp;
		tmpp=__gcd(n,k);
		tn/=tmpp;
		k/=tmpp;
		tm/=k;
		//printf("%d %d\n",tn,tm);
		if (tn*tmp<=n){
			printf("%d 0\n",tn*tmp);
			printf("0 %d\n",tm);
		}
		else{
			printf("%d 0\n",tn);
			printf("0 %d\n",tm*tmp);
		}
	}
	else printf("NO\n");
}