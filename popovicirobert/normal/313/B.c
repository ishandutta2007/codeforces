#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000
char v[MAXN];
int s[MAXN];
int main(){
    int n=0,i,m,l,r;
    char a;
    a=fgetc(stdin);
    while(a=='#'||a=='.'){
        v[n++]=a;
        a=fgetc(stdin);
    }
    for(i=0;i<n-1;i++)
       if(v[i]==v[i+1])
           s[i+1]=s[i]+1;
       else
           s[i+1]=s[i];
    s[n]=s[n-1];
    scanf("%d" ,&m);
    for(i=0;i<m;i++){
        scanf("%d%d" ,&l,&r);
        printf("%d\n" ,s[r-1]-s[l-1]);
    }
    return 0;
}