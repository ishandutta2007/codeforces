#include<stdio.h>
long long out[100100];
int main(){
    int n,i;
    long long x,y;
    scanf("%d%I64d%I64d",&n,&x,&y);
    if(y<n){
	puts("-1");
	return 0;
    }
    for(i=0;i<n;i++)out[i]=1;
    out[0]=y-(n-1);
    long long s=0;
    for(i=0;i<n;i++)s+=out[i]*out[i];
    if(s>=x){
	for(i=0;i<n;i++)printf("%I64d\n",out[i]);
    }else puts("-1");
}