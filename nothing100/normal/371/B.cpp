#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans,num[100][3],tmp;
int gcd(int x,int y)
{
    if (x%y==0) return y;
    else return gcd(y,x%y);
}
void cl(int x)
{
    while (x%2==0)
    {
        x=x/2;
        ans++;
    }
    while (x%3==0)
    {
        x=x/3;
        ans++;
    }
    while (x%5==0)
    {
        x=x/5;
        ans++;
    }
    if (x!=1) ans=-1;
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    tmp=gcd(n,m);
    cl(n/tmp);
    if (ans==-1)
    {
        printf("%d",ans);
        return 0;
    }
    cl(m/tmp);
    printf("%d",ans);
    return 0;
}