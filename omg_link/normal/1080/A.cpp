#include <stdio.h>
int n,k;
int div(int a,int b){
	return a/b+(a%b!=0);
}
int main(){
	scanf("%d%d",&n,&k);
	printf("%d\n",div(2*n,k)+div(5*n,k)+div(8*n,k));
}