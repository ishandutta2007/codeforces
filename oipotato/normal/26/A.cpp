#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
bool check(int x)
{
    int cnt=0;
    for(int i=2;i<=x;i++)if(x%i==0)
    {
        cnt++;
        for(;x%i==0;x/=i);
    }
    return cnt==2;
}
int main()
{
    int n,ans=0;scanf("%d",&n);
    rep(i,n)if(check(i))ans++;
    printf("%d\n",ans);
    return 0;
}