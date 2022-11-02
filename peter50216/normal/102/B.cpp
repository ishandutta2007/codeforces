#include<stdio.h>
char in[100010];
inline int f(int a){
    if(a<10)return 0;
    sprintf(in,"%d",a);
    int c=0;
    for(int i=0;in[i];i++)c+=in[i]-'0';
    return f(c)+1;
}
int main(){
    int i,c=0;
    scanf("%s",in);
    if(in[1]==0){
    puts("0");
    return 0;
    }
    for(i=0;in[i];i++)c+=in[i]-'0';
    printf("%d\n",f(c)+1);
}