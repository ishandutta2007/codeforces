#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return b==0 ? a : gcd(b,a%b);
}
void work(ll a,ll b,int turn)
{
    if(b==0)return;
    printf("%I64d%s",(a-1)/b,(turn ? "B" : "A"));
    work(b,a%b,turn^1);
}
int main()
{
    ll x,y;
    scanf("%I64d%I64d",&x,&y);
    if(gcd(x,y)>1LL)printf("Impossible\n");
    else
    {
        int flag=0;
        if(x<y)
        {
            swap(x,y);
            flag=1;
        }
        work(x,y,flag);
    }
    return 0;
}