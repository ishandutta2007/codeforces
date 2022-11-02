#include<stdio.h>
char in[1010];
bool solve(){
    int i=0;
    while(in[i]&&in[i]!='h')i++;
    if(!in[i])return 0;
    while(in[i]&&in[i]!='e')i++;
    if(!in[i])return 0;
    while(in[i]&&in[i]!='l')i++;
    if(!in[i])return 0;
    i++;
    while(in[i]&&in[i]!='l')i++;
    if(!in[i])return 0;
    while(in[i]&&in[i]!='o')i++;
    if(!in[i])return 0;
    return 1;
}
int main(){
    scanf("%s",in);
    puts(solve()?"YES":"NO");
}