#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN],b[MAXN];
int fp(int a,int k,int m)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%m;
        a=1LL*a*a%m;
        k>>=1;
    }
    return res;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int s[2]={0,0};
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[0]=(s[0]+a[i])%m;
        s[1]=(s[1]+1LL*a[i]*a[i])%m;
    }
    if(n==1)return 0*printf("%d 0",a[1]);
    if(n==m)return 0*printf("0 1");
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        int d=(a[i]-a[1]+m)%m;
        int x=1LL*(s[0]-1LL*n*(n-1)/2%m*d%m+m)*fp(n,m-2,m)%m;
        int tmp=1LL*n*x%m*x%m;
        tmp=(tmp+1LL*n*(n-1)%m*d%m*x%m)%m;
        tmp=(tmp+1LL*n*(n-1)*(2*n-1)/6%m*d%m*d%m)%m;
        if(tmp==s[1])
        {
            b[1]=x;
            for(int i=2;i<=n;i++)
                b[i]=(b[i-1]+d)%m;
            sort(b+1,b+n+1);
            bool isok=1;
            for(int i=1;i<=n;i++)
                isok&=(a[i]==b[i]);
            if(isok)return 0*printf("%d %d",x,d);
        }
    }
    return 0*printf("-1");
}