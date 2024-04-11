#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    bool isok=0;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%*s%d%d",&a,&b);
        if(a>=2400 && b>a)isok=1;
    }
    printf("%s",(isok ? "YES" : "NO"));
    return 0;
}