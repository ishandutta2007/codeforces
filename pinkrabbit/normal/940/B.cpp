#include<cstdio>
#define ll long long
int n,k,A,B;
ll ans;
int main(){
	scanf("%d%d%d%d",&n,&k,&A,&B);
	if(k==1) {printf("%lld",(ll)(n-1)*A);return 0;}
	while(n!=1){
		int x=n/k*k;
		if(x==0) {ans+=(ll)(n-1)*A; break;}
		if(n!=x) ans+=(ll)(n-x)*A, n=x;
		else{
			x=n/k;
			if((ll)(n-x)*A<=B) ans+=(ll)(n-x)*A;
			else ans+=B;
			n=x;
		}
	}
	printf("%lld",ans);
	return 0;
}