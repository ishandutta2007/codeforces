#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int np=0;
    for(int i=1;i<n;i++){
	np=(np+i)%n;
	printf("%d ",np+1);
    }
}