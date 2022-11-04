#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXT=1005;
int t[MAXT];
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        t[a]=max(t[a],b);
    }
    int res=0;
    for(int i=s;i>0;i--)
    {
        res=max(res,t[i]);
        res++;
    }
    printf("%d\n",res);
    return 0;
}