#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int get_even(int x)
{
    if(x<=2)return x;
    else return (x+1)%2;
}
int get_odd(int x)
{
    if(x==0)return 0;
    if(x==1)return 1;
    if(x==2)return 0;
    if(x==3)return 1;
    if(x==4)return 2;
    if(x%2)return 0;
    int cnt=0;
    while(x%2==0)
    {
        x/=2;
        cnt++;
    }
    if(cnt%2)
    {
        if(x==3)return 2;
        else return 1;
    }
    else
    {
        if(x==3)return 1;
        else return 2;
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(k%2==0)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
            sum^=get_even(a[i]);
        if(sum)printf("Kevin\n");
        else printf("Nicky\n");
    }
    else
    {
        int sum=0;
        for(int i=1;i<=n;i++)
            sum^=get_odd(a[i]);
        if(sum)printf("Kevin\n");
        else printf("Nicky\n");
    }
    return 0;
}