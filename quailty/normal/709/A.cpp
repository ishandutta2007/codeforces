#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN];
int main()
{
    int n,b,d;
    scanf("%d%d%d",&n,&b,&d);
    int now=0,res=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a<=b)
        {
            now+=a;
            if(now>d)
            {
                now=0;
                res++;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}