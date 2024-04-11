#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=105;
ll f[MAXN]={1,2};
int main()
{
    for(int i=2;i<MAXN;i++)
        f[i]=f[i-1]+f[i-2];
    ll n;
    scanf("%I64d",&n);
    for(int i=1;i+1<MAXN;i++)
        if(f[i+1]>n)return 0*printf("%d",i);
}