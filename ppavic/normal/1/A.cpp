#include <cstdio>

using namespace std;

int x,y,a;

int main(){
    scanf("%d %d %d",&x,&y,&a);
    long long int m = x/a+1,n = y/a+1;
    if(x%a==0) m--;
    if(y%a==0) n--;
    printf("%I64d",m*n);
}