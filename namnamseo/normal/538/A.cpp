#include <cstdio>

char buf[111];
char needle[]="CODEFORCES";
int n,m=10;

int main(){
    scanf("%s",buf);
    for(n=0;buf[n];++n);
    int i,j;
    for(i=0;buf[i]==needle[i] && i<n && i<m;++i);
    for(j=0;buf[n-1-j]==needle[m-1-j] && j<n && j<m;++j);
    puts(i+j>=m?"YES":"NO");
}