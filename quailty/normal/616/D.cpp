#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500005;
int a[MAXN],c[MAXN<<1];
int main()
{
    int k,n;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int l=1,d=0;
    pair<int,int>res(0,-1);
    for(int r=1;r<=n;r++)
    {
        if(c[a[r]]++==0)d++;
        while(d>k)if(--c[a[l++]]==0)d--;
        if(r-l>res.second-res.first)res=make_pair(l,r);
    }
    printf("%d %d\n",res.first,res.second);
    return 0;
}