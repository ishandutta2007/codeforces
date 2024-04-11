#include <cstdio>

int mn[3];
int mx[3];

int min(int a,int b){ return a>b?b:a; }

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<3;++i) scanf("%d%d",mn+i,mx+i);
    int f;
    f = min(mx[0], n-mn[1]-mn[2]);
    printf("%d ",f); n-=f;
    f = min(mx[1], n-mn[2]);
    printf("%d ",f); n-=f;
    printf("%d\n",n);
    return 0;
}