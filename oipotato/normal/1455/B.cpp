#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int work(int x)
{
    if(x<=2)return (int)1e9;
    x--;
    int now=0,stp=2;
    for(;now+stp<=x;now+=stp,stp++);
    return (int)ceil(1.*(x-now)/(stp-2))+stp-1;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int x;scanf("%d",&x);
        int now=0,ans=0;
        for(;now<x;ans++,now+=ans);
        printf("%d\n",min(ans+now-x,work(x)));
    }
    return 0;
}