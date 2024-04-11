#include <cstdio>

int main()
{
    char from[101];
    char to[101];
    scanf("%s%s",from,to);
    int i;
    int n;
    for(n=0;from[n];++n);
    for(i=0;i<n;++i){
        if(from[i]==to[i]) continue;
        if(from[i]>to[i]){
            puts("No such string");
            return 0;
        } else break;
    }
    int j;
    ++from[n-1];
    for(j=n-1;0<j;--j){
        if(from[j]>'z'){
            from[j]='a';
            ++from[j-1];
        }
    }
    for(i=0;i<n;++i){
        if(from[i]==to[i]) continue;
        if(from[i]>to[i]){
            puts("No such string");
            return 0;
        } else break;
    }
    if(i!=n){
        puts(from);
    } else puts("No such string");
    
    return 0;
}