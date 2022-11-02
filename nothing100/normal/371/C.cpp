#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char ch;
long long n[3],h[3],p[3],m,l,r,mid,ans;
long long max(long long x,long long y)
{
    if (x>y) return x;
    else return y;
}
int check(long long x)
{
    x=max(x*n[0]-h[0],0)*p[0]+max(x*n[1]-h[1],0)*p[1]+max(x*n[2]-h[2],0)*p[2];
    if (x>m) return 0;
    else return 1;
}
int main()
{
    ch=getchar();
    while ((ch=='B')||(ch=='S')||(ch=='C'))
    {
        if (ch=='B') n[0]++;
        else if (ch=='S') n[1]++;
        else if (ch=='C') n[2]++;
        ch=getchar();
    }
    scanf("%I64d%I64d%I64d",&h[0],&h[1],&h[2]);
    scanf("%I64d%I64d%I64d",&p[0],&p[1],&p[2]);
    scanf("%I64d",&m);
    l=0; r=m+h[0]+h[1]+h[2];
    while (l<=r)
    {
        mid=(l+r)/2;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    printf("%I64d",ans);
    return 0;
}