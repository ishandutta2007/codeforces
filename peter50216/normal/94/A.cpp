#include<stdio.h>
#include<string.h>
char in[1000];
char t[10][1000];
int main(){
    scanf("%s",in);
    int i,j;
    for(i=0;i<10;i++)scanf("%s",t[i]);
    for(i=0;i<8;i++){
    for(j=0;j<10;j++)if(strncmp(t[j],in+i*10,10)==0)break;
    printf("%d",j);
    }
}