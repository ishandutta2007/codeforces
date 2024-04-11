#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<=n;i++){
	for(j=0;j<(n-i)*2;j++)printf(" ");
	if(i==0)puts("0");
	else{
	    for(j=0;j<=i;j++)printf("%d ",j);
	    for(j=i-1;j>=0;j--)printf("%d%c",j,(j==0)?'\n':' ');
	}
    }
    for(i=n-1;i>=0;i--){
	for(j=0;j<(n-i)*2;j++)printf(" ");
	if(i==0)puts("0");
	else{
	    for(j=0;j<=i;j++)printf("%d ",j);
	    for(j=i-1;j>=0;j--)printf("%d%c",j,(j==0)?'\n':' ');
	}
    }
}