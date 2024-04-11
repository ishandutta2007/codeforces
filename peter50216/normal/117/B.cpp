#include<stdio.h>
int main(){
    int a,b,m;
    scanf("%d%d%d",&a,&b,&m);
    if(b>=m-1){
	puts("2");
	return 0;
    }
    long long r=1000000000%m;
    for(int i=0;i<m&&i<=a;i++){
	int k=(i*r)%m;
	int l=m-k;
	if(l==m)l=0;
	if(l>b){
	    printf("1 %09d\n",i);
	    return 0;
	}
    }
    puts("2");
}