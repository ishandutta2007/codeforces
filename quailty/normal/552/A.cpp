#include<cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int x1,y1,x2,y2;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ans+=(y2-y1+1)*(x2-x1+1);
    }
    printf("%I64d\n",ans);
    return 0;
}