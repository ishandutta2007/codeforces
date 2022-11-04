#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int s[MAXN],res[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n && s[r]==s[l])r++;
        if(r-l==1)return 0*printf("-1\n");
        for(int i=l;i+1<r;i++)res[i]=i+1;
        res[r-1]=l;
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}