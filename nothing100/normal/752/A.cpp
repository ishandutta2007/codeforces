#include<bits/stdc++.h>
#define MAXN 500010
#define inf 1e+15
using namespace std;
int n,m,k;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    printf("%d %d ",((k-1)/2)/m+1,((k-1)/2)%m+1);
    if (k&1) printf("L\n");
    else printf("R\n");
}