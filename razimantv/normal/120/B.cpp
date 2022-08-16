#include"stdio.h"
int main()
{
    freopen("input.txt", "rt", stdin); 
    freopen("output.txt", "wt", stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];k--;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    while(a[k]==0)k=(k+1)%n;
    printf("%d\n",k+1);
}