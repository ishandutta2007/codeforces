#include <cstdio>

int fx,fy;
int tx,ty;

int main()
{
    scanf("%d%d%d%d",&fx,&fy,&tx,&ty);
    int n;
    scanf("%d",&n);
    int ans=0;
    long long a,b,c;
    for(;n--;)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        ans+=((a*fx+b*fy+c>0LL)!=(a*tx+1LL*b*ty+c>0LL));
    }
    printf("%d\n",ans);
    return 0;
}