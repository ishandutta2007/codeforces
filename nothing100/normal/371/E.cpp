#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct point
{
    long long x,y;
}po[300100];
int n,m,bo[300100],anss;
long long sum;
unsigned long long ans,tmp;
int cmp(point x,point y)
{
    if (x.x<y.x) return 1;
    else return 0;
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%I64d",&po[i].x);
    for (int i=0;i<n;i++) po[i].y=i;
    sort(po,po+n,cmp);
    scanf("%d",&m);
    sum=sum+po[0].x;
    for (int i=1;i<m;i++)
    {
        tmp=tmp+po[i].x*i-sum;
        sum=sum+po[i].x;
    }
    ans=tmp;
    anss=0;
    for (int i=m;i<n;i++)
    {
        sum=sum-po[i-m].x;
        tmp=tmp+po[i-m].x*(m-1)-sum;
        tmp=tmp+po[i].x*(m-1)-sum;
        if (tmp<ans)
        {
            ans=tmp;
            anss=i-m+1;
        }
        sum=sum+po[i].x;
    }
    for (int i=anss;i<anss+m;i++) bo[po[i].y]=1;
    for (int i=0;i<n;i++)
    if (bo[i]) printf("%d ",i+1);
    return 0;
}