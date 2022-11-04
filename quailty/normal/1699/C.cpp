#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
int a[MAXN],loc[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),loc[a[i]]=i;
    int res=1,l=n+1,r=0;
    for(int i=0;i<n;i++)
    {
        bool flag=0;
        if(loc[i]<l)l=loc[i],flag=1;
        if(loc[i]>r)r=loc[i],flag=1;
        if(!flag)res=1LL*res*(r-l+1-i)%Mod;
    }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}