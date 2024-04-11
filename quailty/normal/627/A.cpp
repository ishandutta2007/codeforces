#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[50],b[50];
int main()
{
    ll s,x;
    scanf("%I64d%I64d",&s,&x);
    for(int i=0;i<50;i++)
    {
        if(s&(1LL<<i))a[i]=1;
        if(x&(1LL<<i))b[i]=1;
    }
    ll res=1LL;
    for(int i=49;i>=0;i--)
    {
        if(a[i]>3)return 0*printf("0");
        if(a[i]==3)
        {
            if(b[i]==1)return 0*printf("0");
            else
            {
                a[i]-=2;
                if(i>0)a[i-1]+=2;
            }
        }
        else if(a[i]==2)
        {
            if(b[i]==1)
            {
                res*=2;
                a[i]-=1;
                if(i>0)a[i-1]+=2;
            }
            else a[i]-=2;
        }
        else if(a[i]==1)
        {
            if(b[i]==0)
            {
                if(i>0)a[i-1]+=2;
            }
            else
            {
                a[i]-=1;
                res*=2;
            }
        }
        else
        {
            if(b[i]==1)return 0*printf("0");
        }
    }
    if(a[0]>0)return 0*printf("0");
    printf("%I64d",res-(s==x ? 2 : 0));
    return 0;
}