#include<stdio.h>
char s[100];
int main(){
    int n,i;
    int a=0,b=0;
    scanf("%d%s",&n,s);
    if(n%2)puts("NO");
    else{
        for(i=0;i<n/2;i++)a+=s[i];
        for(i=n/2;i<n;i++)b+=s[i];
        for(i=0;i<n;i++)if(s[i]!='4'&&s[i]!='7')break;
        puts(i==n&&a==b?"YES":"NO");
    }
}