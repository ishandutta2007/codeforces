#include<stdio.h>
int in[1001000];
int a[1001000];
int dp[1001000];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
	int t;
	scanf("%d",&t);
	a[t]=i;
    }
    for(i=1;i<=n;i++){
	int t;
	scanf("%d",&t);
	in[a[t]]=i;
    }
    dp[0]=100000000;
    int c=0;
    for(i=1;i<=n;i++){
	int l=0,r=c;
	while(l<r){
	    int m=(l+r+1)/2;
	    if(dp[m]>in[i])l=m;
	    else r=m-1;
	}
	dp[l+1]=in[i];
	if(l+1>c)c=l+1;
    }
    printf("%d\n",c);
}