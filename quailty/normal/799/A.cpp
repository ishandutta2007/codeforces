#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,t,k,d;
    scanf("%d%d%d%d",&n,&t,&k,&d);
    int f[2]={0,d},now=0;
    for(int i=0;i<n;i+=k)
    {
        int id=(f[0]>f[1]);
        now=max(now,f[id]+=t);
    }
    return 0*printf("%s",(now<(n+k-1)/k*t ? "YES" : "NO"));
}