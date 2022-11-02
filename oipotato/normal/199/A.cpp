#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int f[100010];
int main()
{
    f[0]=0;f[1]=1;
    for(int i=1;f[i]<(int)1e9;i++,f[i]=f[i-1]+f[i-2]);
    int n;scanf("%d",&n);
    if(!n)puts("0 0 0");
    else if(n==1)puts("0 0 1");
    else for(int i=2;;i++)if(f[i]==n){printf("0 %d %d\n",f[i-2],f[i-1]);return 0;}
    return 0;
}