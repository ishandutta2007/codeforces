#include<stdio.h>
int main(){
    long long n,m,t;
    scanf("%I64d%I64d%I64d",&n,&m,&t);
    long long a=0;
    for(int i=4;i<=n;i++){
	if(t-i<=m&&t-i>=1){
	    long long x=1;
	    for(int j=1;j<=i;j++)x=x*(n-j+1)/j;
	    for(int j=1;j<=t-i;j++)x=x*(m-j+1)/j;
	    a+=x;
	}
    }
    printf("%I64d\n",a);
}