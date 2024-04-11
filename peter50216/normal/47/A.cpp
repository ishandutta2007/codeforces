#include<stdio.h>
int t(int a){return a*(a-1)/2;}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;t(i)<n;i++);
    puts(t(i)==n?"YES":"NO");
}