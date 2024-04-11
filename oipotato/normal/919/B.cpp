#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int ans[10010];
bool check(int x)
{
    int sum=0;
    for(;x;sum+=x%10,x/=10);
    return sum==10;
}
int main()
{
    int cnt=0;
    rep(i,30000000)
    {
        if(check(i))ans[++cnt]=i;
        if(cnt==10000)break;
    }
    int k;scanf("%d",&k);
    printf("%d\n",ans[k]);
    return 0;
}