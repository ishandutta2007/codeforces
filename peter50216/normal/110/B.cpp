#include<stdio.h>
int main(){

    int n,c=0;
    scanf("%d",&n);
    while(n--){
	printf("%c",c+'a');
	c=(c+1)%4;
    }
}