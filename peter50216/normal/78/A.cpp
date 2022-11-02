#include<stdio.h>
char in[1000];
int gn(){
    gets(in);
    int a=0;
    for(int i=0;in[i];i++){
    if(in[i]=='a'||in[i]=='e'||in[i]=='i'||in[i]=='o'||in[i]=='u')a++;
    }
    return a;
}
int main(){
    int a,b,c;
    a=gn();b=gn();c=gn();
    puts(a==5&&b==7&&c==5?"YES":"NO");
}