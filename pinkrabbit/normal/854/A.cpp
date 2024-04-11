#include<cstdio>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;(i<<1)<n;++i) if(gcd(i,n-i)==1) ans=i;
	printf("%d %d\n",ans,n-ans);
	return 0;
}