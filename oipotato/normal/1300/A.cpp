#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int cal(LL x)
{
    int res=0;
    for(;x;res+=x%10,x/=10);
    return res;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,sum=0,cnt=0;
        scanf("%d",&n);
        rep(i,n)
        {
            int x;scanf("%d",&x);
            if(!x)cnt++;
            sum+=x;
        }
        if(sum+cnt==0)cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}