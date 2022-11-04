#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int T,S,q;
    scanf("%d%d%d",&T,&S,&q);
    int ans=0;
    while(S<T)
    {
        ans++;
        S*=q;
    }
    printf("%d\n",ans);
    return 0;
}