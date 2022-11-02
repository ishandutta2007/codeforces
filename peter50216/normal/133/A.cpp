#include<stdio.h>
char in[1000];
int main(){
    scanf("%s",in);
    int i;
    for(i=0;in[i];i++)if(in[i]=='H'||in[i]=='Q'||in[i]=='9')break;
    puts(in[i]?"YES":"NO");
}