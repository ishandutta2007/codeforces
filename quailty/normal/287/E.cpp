#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=1000005;
int x[MAXN],y[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int q;
        scanf("%d",&q);
        x[q]*=-1;
    }
    stack<int>stk;
    for(int i=n;i>=1;i--)
    {
        if(x[i]<0)
        {
            y[i]=x[i];
            stk.push(x[i]);
        }
        else
        {
            if(!stk.empty() && stk.top()==-x[i])
            {
                y[i]=x[i];
                stk.pop();
            }
            else
            {
                y[i]=-x[i];
                stk.push(-x[i]);
            }
        }
    }
    if(!stk.empty())printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i=1;i<=n;i++)
            printf("%d ",y[i]);
    }
    return 0;
}