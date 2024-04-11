#include <cstdio>


int main(){
    int n,x;
    scanf("%d" ,&n);
    if(n%7>2)
       x=2;
    else
       x=n%7;
    printf("%d %d" ,(n/7)*2+(n%7==6),(n/7)*2+x);
    return 0;
}