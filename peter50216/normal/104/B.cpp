#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    long long ans=n;
    for(i=0;i<n;i++){
	int a;
	scanf("%d",&a);
	ans+=(a-1)*(i+1ll);
    }
    printf("%I64d\n",ans);
}