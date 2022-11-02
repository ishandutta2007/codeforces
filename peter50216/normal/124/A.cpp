#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    printf("%d\n",min(n-a-1,b)+1);
}