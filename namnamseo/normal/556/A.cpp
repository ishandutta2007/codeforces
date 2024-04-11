#include <cstdio>

int n;
char buf[200010];

int max(int a,int b){ return a>b?a:b; }
int min(int a,int b){ return a<b?a:b; }

int main()
{
    scanf("%d",&n);
    scanf("%s",buf);
    int i;
    int cc[2]={0,0};
    for(i=0;i<n;++i) ++cc[buf[i]-48];
    printf("%d\n",n-min(cc[0],cc[1])*2);
    return 0;
}