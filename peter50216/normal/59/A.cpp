#include<stdio.h>
char in[1000];
int main(){
    scanf("%s",in);
    int i;
    int c1=0,c2=0;
    for(i=0;in[i];i++){
    if(in[i]>='A'&&in[i]<='Z')c1++;
    else{
        c2++;
        in[i]=in[i]-'a'+'A';
    }
    }
    if(c1<=c2){
    for(i=0;in[i];i++)in[i]=in[i]-'A'+'a';
    }
    puts(in);
}