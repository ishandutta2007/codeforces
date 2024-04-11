#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int mn=101,n,ans=0;
    scanf("%d",&n);
    rep(i,n)
    {
        int a,p;scanf("%d%d",&a,&p);
        mn=min(mn,p);
        ans+=mn*a;
    }
    printf("%d\n",ans);
    return 0;
}