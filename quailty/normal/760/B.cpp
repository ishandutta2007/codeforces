#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cal(int n,int k,int r)
{
    ll res=0;
    if(r>k)res+=1LL*k*(2*r-k+1)/2;
    else res+=1LL*r*(r+1)/2+(k-r);
    if(r>n-k)res+=1LL*(n-k+1)*(2*r-n+k)/2;
    else res+=1LL*r*(r+1)/2+(n-k-r+1);
    return res-r;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int tl=1,tr=m;
    while(tl<tr)
    {
        int tm=(tl+tr+1)/2;
        if(cal(n,k,tm)<=m)tl=tm;
        else tr=tm-1;
    }
    return 0*printf("%d",tl);
}