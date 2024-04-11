#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,p,k;
    scanf("%d%d%d",&n,&p,&k);
    printf("%s",(p-k>1?"<< ":""));
    for(int i=max(1,p-k);i<p;i++)
        printf("%d ",i);
    printf("(%d)",p);
    for(int i=p+1;i<=min(n,p+k);i++)
        printf(" %d",i);
    printf("%s",(p+k<n?" >>":""));
    return 0;
}