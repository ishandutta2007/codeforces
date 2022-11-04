#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    int l=0,r=1000;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        l=max(l,a);
        r=min(r,b);
    }
    int res;
    if(l>r)res=-1;
    else if(x<l)res=l-x;
    else if(x>r)res=x-r;
    else res=0;
    printf("%d\n",res);
    return 0;
}