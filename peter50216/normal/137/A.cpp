#include<stdio.h>
char in[1000];
int main(){
    int i,j;
    scanf("%s",in);
    int a=0;
    for(i=0;in[i];i=j){
        for(j=i;in[j]&&j<i+5&&in[j]==in[i];j++);
        a++;
    }
    printf("%d\n",a);
}