#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
struct node
{
    int a,b;
    node(){}
    node(int _a,int _b):a(_a),b(_b){}
    bool operator < (const node &t)const
    {
        return a<t.a;
    }
}s[MAXN];
int dp[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&s[i].a,&s[i].b);
    sort(s+1,s+n+1);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int t=lower_bound(s+1,s+n+1,node(s[i].a-s[i].b,0))-(s+1);
        dp[i]=dp[t]+1;
        res=max(res,dp[i]);
    }
    printf("%d\n",n-res);
    return 0;
}