#include<stdio.h>
char aa[1000],bb[1000],cc[1000];
int main(){
    int a,c;
    scanf("%d%d",&a,&c);
    int a1=0,c1=0;
    while(a){
	aa[a1++]=a%3;
	a/=3;
    }
    while(c){
	cc[c1++]=c%3;
	c/=3;
    }
    if(a1<c1)a1=c1;
    long long b=0;
    for(int i=0;i<a1;i++)cc[i]=(cc[i]-aa[i]+3)%3;
    for(int i=a1-1;i>=0;i--)b=b*3+cc[i];
    printf("%I64d\n",b);
}