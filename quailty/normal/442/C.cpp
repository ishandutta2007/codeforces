#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll stk[MAXN],top;
int main()
{
    int n;
    scanf("%d",&n);
    ll a,res=0;
    while(n--)
    {
        scanf("%I64d",&a);
        while(top>=2 && stk[top-2]>=stk[top-1] && stk[top-1]<=a)
        {
            res+=min(stk[top-2],a);
            top--;
        }
        stk[top++]=a;
    }
    ll mx[2]={0,0};
    for(int i=0;i<top;i++)
    {
        res+=stk[i];
        if(stk[i]>mx[0])
        {
            mx[1]=mx[0];
            mx[0]=stk[i];
        }
        else if(stk[i]>mx[1])
            mx[1]=stk[i];
    }
    return 0*printf("%I64d",res-mx[0]-mx[1]);
}