#include<bits/stdc++.h>
using namespace std;
const int MAXN=400005;
int mx[MAXN];
int main()
{
    int q,x;
    scanf("%d%d",&q,&x);
    for(int i=0;i<x;i++)
        mx[i]=i-x;
    int res=0;
    for(int i=1;i<=q;i++)
    {
        int y;
        scanf("%d",&y);
        mx[y%x]+=x;
        while(res<=mx[res%x])res++;
        printf("%d\n",res);
    }
    return 0;
}