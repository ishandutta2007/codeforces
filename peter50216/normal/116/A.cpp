#include<stdio.h>
int main(){
    int n,a=0,ma=0;
    scanf("%d",&n);
    while(n--){
	int x,y;
	scanf("%d%d",&x,&y);
	a-=x;
	a+=y;
	if(ma<a)ma=a;
    }
    printf("%d\n",ma);
}