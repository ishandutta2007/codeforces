#include<bits/stdc++.h>
using namespace std;
char s[66];
int main(){
    int n;
    scanf("%s",s);
    n=strlen(s);
    int cnt=0;
    for(char *i=s;*i;++i)if((isalpha(*i)&&(*i=='a'||*i=='e'||*i=='i'||*i=='o'||*i=='u'))||(isdigit(*i)&&((*i-'0')%2)))++cnt;
    printf("%d\n",cnt);
    return 0;
}