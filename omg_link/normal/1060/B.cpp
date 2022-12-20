#include <stdio.h>
typedef long long LL;
LL n,a,b;
int ans=0;
char sa[20],sb[20];
int main(){
	scanf("%lld",&n);
	for(a=1;a-1<=n;a*=10); 
	if(a>=10)a/=10;
	a--; b=n-a;
	sprintf(&sa[1],"%lld",a);
	sprintf(&sb[1],"%lld",b);
	for(int i=1;sa[i]!='\0';i++) ans+=sa[i]-'0';
	for(int i=1;sb[i]!='\0';i++) ans+=sb[i]-'0';
	printf("%d",ans);
}