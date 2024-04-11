#include<stdio.h>
char ans[5][10]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
inline int solve(int n){
    n--;
    int nn=n/5+1;
    int c=1;
    while(c<=nn)c*=2;
    return (n-(c/2-1)*5)/(c/2);
}
int main(){
    int n;
    scanf("%d",&n);
    puts(ans[solve(n)]);
}