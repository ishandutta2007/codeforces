#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
    if(a==0 && b==0)return -1;
    if(b==0)return x=1,y=0,a;
    int d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}
int inv(int a,int n)
{
    int x,y,d=exgcd(a,n,x,y);
    return (d==1 ? (x%n+n)%n : -1);
}
int cnt[1000005];
int main()
{
    int n,m,dx,dy;
    scanf("%d%d%d%d",&n,&m,&dx,&dy);
    int t=inv(dx,n);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int go=1LL*t*(n-x)%n;
        cnt[(y+1LL*go*dy)%n]++;
    }
    int res=0;
    for(int i=0;i<n;i++)
        if(cnt[i]>cnt[res])res=i;
    printf("%d %d\n",0,res);
    return 0;
}