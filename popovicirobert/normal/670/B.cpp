#include <cstdio>
int v[100001];
int main(){
    int n,k,i;
    long long x;
    scanf("%d%d" ,&n,&k);
    for(i=1;i<=n;i++)
      scanf("%d" ,&v[i]);
    x=1;
    while((x*(x+1))/2<=k)
       x++;
    x--;
    if(k==(x*(x+1))/2)
       printf("%d" ,v[x]);
    else
       printf("%d" ,v[k-(x*(x+1))/2]);
    return 0;
}