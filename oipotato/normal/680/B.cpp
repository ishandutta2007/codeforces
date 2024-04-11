#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,a,t[110],ans=0;
    scanf("%d%d",&n,&a);
    rep(i,n)scanf("%d",&t[i]);
    rep(i,n)
    if(t[i])
    {
        int dis=abs(i-a);
        int other=i<a?a+dis:a-dis;
        if(other<1||other>n||t[other])ans++;
    }
    printf("%d\n",ans);
    return 0;
}