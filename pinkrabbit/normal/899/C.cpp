#include<cstdio>
int n;
long long s,sum;
int main(){
	scanf("%d",&n);
	s=1ll*n*(n+1)/2;
	int i=n;
	for(;i>=1;--i){
		sum+=i;
		if(sum>=s/2) break;
	}
	printf("%d\n",s&1);
	if(s/2==sum){
		printf("%d ",n-i+1);
		for(;i<=n;++i) printf("%d ",i);
	}
	else{
		sum-=i;
		printf("%d %d ",n-i+1,s/2-sum);
		for(++i;i<=n;++i) printf("%d ",i);
	}
	return 0;
}